/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeQdd.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "computeQdd.h"
#include "simulateDNA_emxutil.h"
#include "xgetrf.h"
#include "qrsolve.h"
#include "xgeqp3.h"
#include "eye.h"
#include "getForces.h"
#include "getDk.h"

/* Function Definitions */

/*
 * Arguments    : double t
 *                const emxArray_real_T *state
 *                const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                const emxArray_real_T *DNA_Mpar
 *                const emxArray_real_T *DNA_Hpar
 *                const emxArray_real_T *DNA_Spar
 *                const emxArray_real_T *DNA_Ppar
 *                const emxArray_real_T *DNA_Pmpar
 *                emxArray_real_T *qdd
 * Return Type  : void
 */
void computeQdd(double t, const emxArray_real_T *state, const emxArray_real_T
                *DNA_incstr, const emxArray_real_T *DNA_edgelabel, const
                emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar,
                const emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar,
                const emxArray_real_T *DNA_Pmpar, emxArray_real_T *qdd)
{
  double nX;
  int i9;
  int i10;
  emxArray_real_T *F;
  emxArray_real_T *unusedU0;
  emxArray_real_T *Dq;
  emxArray_real_T *Dqq;
  emxArray_real_T *Dqt;
  emxArray_real_T *Dtt;
  int i11;
  int i;
  int kAcol;
  int loop_ub;
  emxArray_real_T *Mij;
  int nM;
  double wj;
  int k;
  emxArray_real_T *eomLHS;
  int m;
  int u0;
  boolean_T empty_non_axis_sizes;
  int mn;
  emxArray_real_T *result;
  cell_wrap_0 reshapes[2];
  emxArray_real_T *b_result;
  cell_wrap_0 b_reshapes[2];
  emxArray_real_T *eomRHS;
  emxArray_int32_T *jpvt;
  unsigned int unnamed_idx_0;
  nX = (double)state->size[0] / 2.0;

  /* Get the number of coordinates */
  if (nX + 1.0 > state->size[0]) {
    i9 = 1;
    i10 = 1;
  } else {
    i9 = (int)(nX + 1.0);
    i10 = state->size[0] + 1;
  }

  emxInit_real_T1(&F, 1);
  emxInit_real_T1(&unusedU0, 1);
  emxInit_real_T(&Dq, 2);
  emxInit_real_T1(&Dqq, 1);
  emxInit_real_T1(&Dqt, 1);
  emxInit_real_T1(&Dtt, 1);

  /* Get the velocity vector */
  d_getDk(t, state, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
          DNA_Ppar, DNA_Pmpar, unusedU0, Dq, Dqq, F, Dqt, Dtt);

  /* Get Jacobian and convective accelerations */
  getForces(t, state, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
            DNA_Ppar, DNA_Pmpar, F);
  if (2 > DNA_Mpar->size[0]) {
    i11 = 0;
    i = 0;
  } else {
    i11 = 1;
    i = DNA_Mpar->size[0];
  }

  kAcol = unusedU0->size[0];
  unusedU0->size[0] = i - i11;
  emxEnsureCapacity((emxArray__common *)unusedU0, kAcol, (int)sizeof(double));
  loop_ub = i - i11;
  for (kAcol = 0; kAcol < loop_ub; kAcol++) {
    unusedU0->data[kAcol] = 0.083333333333333329 * DNA_Mpar->data[(i11 + kAcol)
      + (DNA_Mpar->size[0] << 1)];
  }

  emxInit_real_T(&Mij, 2);
  nM = (i - i11) - 1;
  wj = (double)(i - i11) * 3.0;
  i = Mij->size[0] * Mij->size[1];
  Mij->size[0] = (int)wj;
  Mij->size[1] = (int)wj;
  emxEnsureCapacity((emxArray__common *)Mij, i, (int)sizeof(double));
  loop_ub = (int)wj * (int)wj;
  for (i = 0; i < loop_ub; i++) {
    Mij->data[i] = 0.0;
  }

  /* Build mass matrix */
  for (k = 0; k <= nM; k++) {
    Mij->data[((int)((1.0 + (double)k) * 3.0 - 2.0) + Mij->size[0] * ((int)((1.0
      + (double)k) * 3.0 - 2.0) - 1)) - 1] = DNA_Mpar->data[(i11 + k) +
      (DNA_Mpar->size[0] << 1)];
    Mij->data[((int)((1.0 + (double)k) * 3.0 - 1.0) + Mij->size[0] * ((int)((1.0
      + (double)k) * 3.0 - 1.0) - 1)) - 1] = DNA_Mpar->data[(i11 + k) +
      (DNA_Mpar->size[0] << 1)];
    Mij->data[((int)((1.0 + (double)k) * 3.0) + Mij->size[0] * ((int)((1.0 +
      (double)k) * 3.0) - 1)) - 1] = unusedU0->data[k];
  }

  emxInit_real_T(&eomLHS, 2);
  m = Dq->size[0];
  i11 = eomLHS->size[0] * eomLHS->size[1];
  eomLHS->size[0] = Dq->size[1];
  eomLHS->size[1] = Dq->size[0];
  emxEnsureCapacity((emxArray__common *)eomLHS, i11, (int)sizeof(double));
  loop_ub = Dq->size[0];
  for (i11 = 0; i11 < loop_ub; i11++) {
    kAcol = Dq->size[1];
    for (i = 0; i < kAcol; i++) {
      eomLHS->data[i + eomLHS->size[0] * i11] = Dq->data[i11 + Dq->size[0] * i];
    }
  }

  if (!((Mij->size[0] == 0) || (Mij->size[1] == 0))) {
    u0 = Mij->size[0];
  } else if (!((eomLHS->size[0] == 0) || (eomLHS->size[1] == 0))) {
    u0 = eomLHS->size[0];
  } else {
    u0 = Mij->size[0];
    if (u0 >= 0) {
    } else {
      u0 = 0;
    }

    if (eomLHS->size[0] > u0) {
      u0 = eomLHS->size[0];
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || (!((Mij->size[0] == 0) || (Mij->size[1] == 0)))) {
    mn = Mij->size[1];
  } else {
    mn = 0;
  }

  if (empty_non_axis_sizes || (!((eomLHS->size[0] == 0) || (eomLHS->size[1] == 0))))
  {
    kAcol = eomLHS->size[1];
  } else {
    kAcol = 0;
  }

  emxInit_real_T(&result, 2);
  i11 = result->size[0] * result->size[1];
  result->size[0] = u0;
  result->size[1] = mn + kAcol;
  emxEnsureCapacity((emxArray__common *)result, i11, (int)sizeof(double));
  for (i11 = 0; i11 < mn; i11++) {
    for (i = 0; i < u0; i++) {
      result->data[i + result->size[0] * i11] = Mij->data[i + u0 * i11];
    }
  }

  for (i11 = 0; i11 < kAcol; i11++) {
    for (i = 0; i < u0; i++) {
      result->data[i + result->size[0] * (i11 + mn)] = eomLHS->data[i + u0 * i11];
    }
  }

  if (!((Dq->size[0] == 0) || (Dq->size[1] == 0))) {
    u0 = Dq->size[0];
  } else if (!(m == 0)) {
    u0 = m;
  } else {
    u0 = Dq->size[0];
    if (u0 >= 0) {
    } else {
      u0 = 0;
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || (!((Dq->size[0] == 0) || (Dq->size[1] == 0)))) {
    mn = Dq->size[1];
  } else {
    mn = 0;
  }

  if (empty_non_axis_sizes || (!(m == 0))) {
  } else {
    m = 0;
  }

  emxInitMatrix_cell_wrap_0(reshapes);
  i11 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
  reshapes[1].f1->size[0] = u0;
  reshapes[1].f1->size[1] = m;
  emxEnsureCapacity((emxArray__common *)reshapes[1].f1, i11, (int)sizeof(double));
  loop_ub = u0 * m;
  for (i11 = 0; i11 < loop_ub; i11++) {
    reshapes[1].f1->data[i11] = 0.0;
  }

  emxInit_real_T(&b_result, 2);
  i11 = b_result->size[0] * b_result->size[1];
  b_result->size[0] = u0;
  b_result->size[1] = mn + reshapes[1].f1->size[1];
  emxEnsureCapacity((emxArray__common *)b_result, i11, (int)sizeof(double));
  for (i11 = 0; i11 < mn; i11++) {
    for (i = 0; i < u0; i++) {
      b_result->data[i + b_result->size[0] * i11] = Dq->data[i + u0 * i11];
    }
  }

  emxFree_real_T(&Dq);
  loop_ub = reshapes[1].f1->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    kAcol = reshapes[1].f1->size[0];
    for (i = 0; i < kAcol; i++) {
      b_result->data[i + b_result->size[0] * (i11 + mn)] = reshapes[1].f1->
        data[i + reshapes[1].f1->size[0] * i11];
    }
  }

  emxFreeMatrix_cell_wrap_0(reshapes);
  if (!((result->size[0] == 0) || (result->size[1] == 0))) {
    u0 = result->size[1];
  } else if (!((b_result->size[0] == 0) || (b_result->size[1] == 0))) {
    u0 = b_result->size[1];
  } else {
    u0 = result->size[1];
    if (u0 >= 0) {
    } else {
      u0 = 0;
    }

    if (b_result->size[1] > u0) {
      u0 = b_result->size[1];
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || (!((result->size[0] == 0) || (result->size[1] == 0))))
  {
    mn = result->size[0];
  } else {
    mn = 0;
  }

  if (empty_non_axis_sizes || (!((b_result->size[0] == 0) || (b_result->size[1] ==
         0)))) {
    kAcol = b_result->size[0];
  } else {
    kAcol = 0;
  }

  i11 = Mij->size[0] * Mij->size[1];
  Mij->size[0] = mn + kAcol;
  Mij->size[1] = u0;
  emxEnsureCapacity((emxArray__common *)Mij, i11, (int)sizeof(double));
  for (i11 = 0; i11 < u0; i11++) {
    for (i = 0; i < mn; i++) {
      Mij->data[i + Mij->size[0] * i11] = result->data[i + mn * i11];
    }
  }

  for (i11 = 0; i11 < u0; i11++) {
    for (i = 0; i < kAcol; i++) {
      Mij->data[(i + mn) + Mij->size[0] * i11] = b_result->data[i + kAcol * i11];
    }
  }

  if ((Mij->size[0] == 0) || (Mij->size[1] == 0)) {
    m = 0;
  } else {
    u0 = Mij->size[0];
    m = Mij->size[1];
    if (u0 >= m) {
      m = u0;
    }
  }

  eye(i10 - i9, eomLHS);
  if (!((eomLHS->size[0] == 0) || (eomLHS->size[1] == 0))) {
    u0 = eomLHS->size[0];
  } else if (!((i10 - i9 == 0) || (m == 0))) {
    u0 = i10 - i9;
  } else {
    u0 = eomLHS->size[0];
    if (u0 >= 0) {
    } else {
      u0 = 0;
    }

    if (i10 - i9 > u0) {
      u0 = i10 - i9;
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || (!((eomLHS->size[0] == 0) || (eomLHS->size[1] == 0))))
  {
    mn = eomLHS->size[1];
  } else {
    mn = 0;
  }

  if (empty_non_axis_sizes || (!((i10 - i9 == 0) || (m == 0)))) {
  } else {
    m = 0;
  }

  emxInitMatrix_cell_wrap_0(b_reshapes);
  i11 = b_reshapes[1].f1->size[0] * b_reshapes[1].f1->size[1];
  b_reshapes[1].f1->size[0] = u0;
  b_reshapes[1].f1->size[1] = m;
  emxEnsureCapacity((emxArray__common *)b_reshapes[1].f1, i11, (int)sizeof
                    (double));
  loop_ub = u0 * m;
  for (i11 = 0; i11 < loop_ub; i11++) {
    b_reshapes[1].f1->data[i11] = 0.0;
  }

  i11 = result->size[0] * result->size[1];
  result->size[0] = u0;
  result->size[1] = mn + b_reshapes[1].f1->size[1];
  emxEnsureCapacity((emxArray__common *)result, i11, (int)sizeof(double));
  for (i11 = 0; i11 < mn; i11++) {
    for (i = 0; i < u0; i++) {
      result->data[i + result->size[0] * i11] = eomLHS->data[i + u0 * i11];
    }
  }

  loop_ub = b_reshapes[1].f1->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    kAcol = b_reshapes[1].f1->size[0];
    for (i = 0; i < kAcol; i++) {
      result->data[i + result->size[0] * (i11 + mn)] = b_reshapes[1].f1->data[i
        + b_reshapes[1].f1->size[0] * i11];
    }
  }

  emxFreeMatrix_cell_wrap_0(b_reshapes);
  kAcol = i10 - i9;
  if ((Mij->size[0] == 0) || (Mij->size[1] == 0)) {
    m = 0;
  } else {
    u0 = Mij->size[0];
    m = Mij->size[1];
    if (u0 >= m) {
      m = u0;
    }
  }

  i11 = eomLHS->size[0] * eomLHS->size[1];
  eomLHS->size[0] = m;
  eomLHS->size[1] = kAcol;
  emxEnsureCapacity((emxArray__common *)eomLHS, i11, (int)sizeof(double));
  for (i11 = 0; i11 < kAcol; i11++) {
    for (i = 0; i < m; i++) {
      eomLHS->data[i + eomLHS->size[0] * i11] = 0.0;
    }
  }

  if (!((eomLHS->size[0] == 0) || (eomLHS->size[1] == 0))) {
    u0 = eomLHS->size[0];
  } else if (!((Mij->size[0] == 0) || (Mij->size[1] == 0))) {
    u0 = Mij->size[0];
  } else {
    u0 = eomLHS->size[0];
    if (u0 >= 0) {
    } else {
      u0 = 0;
    }

    if (Mij->size[0] > u0) {
      u0 = Mij->size[0];
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || (!((eomLHS->size[0] == 0) || (eomLHS->size[1] == 0))))
  {
    mn = eomLHS->size[1];
  } else {
    mn = 0;
  }

  if (empty_non_axis_sizes || (!((Mij->size[0] == 0) || (Mij->size[1] == 0)))) {
    kAcol = Mij->size[1];
  } else {
    kAcol = 0;
  }

  i11 = b_result->size[0] * b_result->size[1];
  b_result->size[0] = u0;
  b_result->size[1] = mn + kAcol;
  emxEnsureCapacity((emxArray__common *)b_result, i11, (int)sizeof(double));
  for (i11 = 0; i11 < mn; i11++) {
    for (i = 0; i < u0; i++) {
      b_result->data[i + b_result->size[0] * i11] = eomLHS->data[i + u0 * i11];
    }
  }

  for (i11 = 0; i11 < kAcol; i11++) {
    for (i = 0; i < u0; i++) {
      b_result->data[i + b_result->size[0] * (i11 + mn)] = Mij->data[i + u0 *
        i11];
    }
  }

  if (!((result->size[0] == 0) || (result->size[1] == 0))) {
    u0 = result->size[1];
  } else if (!((b_result->size[0] == 0) || (b_result->size[1] == 0))) {
    u0 = b_result->size[1];
  } else {
    u0 = result->size[1];
    if (u0 >= 0) {
    } else {
      u0 = 0;
    }

    if (b_result->size[1] > u0) {
      u0 = b_result->size[1];
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || (!((result->size[0] == 0) || (result->size[1] == 0))))
  {
    mn = result->size[0];
  } else {
    mn = 0;
  }

  if (empty_non_axis_sizes || (!((b_result->size[0] == 0) || (b_result->size[1] ==
         0)))) {
    kAcol = b_result->size[0];
  } else {
    kAcol = 0;
  }

  i11 = eomLHS->size[0] * eomLHS->size[1];
  eomLHS->size[0] = mn + kAcol;
  eomLHS->size[1] = u0;
  emxEnsureCapacity((emxArray__common *)eomLHS, i11, (int)sizeof(double));
  for (i11 = 0; i11 < u0; i11++) {
    for (i = 0; i < mn; i++) {
      eomLHS->data[i + eomLHS->size[0] * i11] = result->data[i + mn * i11];
    }
  }

  emxFree_real_T(&result);
  for (i11 = 0; i11 < u0; i11++) {
    for (i = 0; i < kAcol; i++) {
      eomLHS->data[(i + mn) + eomLHS->size[0] * i11] = b_result->data[i + kAcol *
        i11];
    }
  }

  emxFree_real_T(&b_result);
  emxInit_real_T1(&eomRHS, 1);
  i11 = eomRHS->size[0];
  eomRHS->size[0] = ((i10 - i9) + F->size[0]) + Dqt->size[0];
  emxEnsureCapacity((emxArray__common *)eomRHS, i11, (int)sizeof(double));
  loop_ub = i10 - i9;
  for (i11 = 0; i11 < loop_ub; i11++) {
    eomRHS->data[i11] = state->data[(i9 + i11) - 1];
  }

  loop_ub = F->size[0];
  for (i11 = 0; i11 < loop_ub; i11++) {
    eomRHS->data[(i11 + i10) - i9] = F->data[i11];
  }

  loop_ub = Dqt->size[0];
  for (i11 = 0; i11 < loop_ub; i11++) {
    eomRHS->data[((i11 + i10) - i9) + F->size[0]] = -((2.0 * Dqt->data[i11] +
      Dqq->data[i11]) + Dtt->data[i11]);
  }

  emxFree_real_T(&Dtt);
  emxFree_real_T(&Dqt);
  emxFree_real_T(&Dqq);
  emxFree_real_T(&F);
  emxInit_int32_T1(&jpvt, 2);
  if ((eomLHS->size[0] == 0) || (eomLHS->size[1] == 0) || (eomRHS->size[0] == 0))
  {
    unnamed_idx_0 = (unsigned int)eomLHS->size[1];
    i9 = qdd->size[0];
    qdd->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity((emxArray__common *)qdd, i9, (int)sizeof(double));
    loop_ub = (int)unnamed_idx_0;
    for (i9 = 0; i9 < loop_ub; i9++) {
      qdd->data[i9] = 0.0;
    }
  } else if (eomLHS->size[0] == eomLHS->size[1]) {
    m = eomLHS->size[1];
    i9 = Mij->size[0] * Mij->size[1];
    Mij->size[0] = eomLHS->size[0];
    Mij->size[1] = eomLHS->size[1];
    emxEnsureCapacity((emxArray__common *)Mij, i9, (int)sizeof(double));
    loop_ub = eomLHS->size[0] * eomLHS->size[1];
    for (i9 = 0; i9 < loop_ub; i9++) {
      Mij->data[i9] = eomLHS->data[i9];
    }

    xgetrf(eomLHS->size[1], eomLHS->size[1], Mij, eomLHS->size[1], jpvt, &kAcol);
    i9 = qdd->size[0];
    qdd->size[0] = eomRHS->size[0];
    emxEnsureCapacity((emxArray__common *)qdd, i9, (int)sizeof(double));
    loop_ub = eomRHS->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      qdd->data[i9] = eomRHS->data[i9];
    }

    for (kAcol = 0; kAcol + 1 < m; kAcol++) {
      if (jpvt->data[kAcol] != kAcol + 1) {
        wj = qdd->data[kAcol];
        qdd->data[kAcol] = qdd->data[jpvt->data[kAcol] - 1];
        qdd->data[jpvt->data[kAcol] - 1] = wj;
      }
    }

    for (k = 0; k + 1 <= m; k++) {
      kAcol = m * k;
      if (qdd->data[k] != 0.0) {
        for (i = k + 1; i + 1 <= m; i++) {
          qdd->data[i] -= qdd->data[k] * Mij->data[i + kAcol];
        }
      }
    }

    for (k = eomLHS->size[1] - 1; k + 1 > 0; k--) {
      kAcol = m * k;
      if (qdd->data[k] != 0.0) {
        wj = Mij->data[k + kAcol];
        qdd->data[k] /= wj;
        for (i = 0; i + 1 <= k; i++) {
          qdd->data[i] -= qdd->data[k] * Mij->data[i + kAcol];
        }
      }
    }
  } else {
    xgeqp3(eomLHS, unusedU0, jpvt);
    loop_ub = rankFromQR(eomLHS);
    kAcol = eomLHS->size[1];
    i9 = qdd->size[0];
    qdd->size[0] = kAcol;
    emxEnsureCapacity((emxArray__common *)qdd, i9, (int)sizeof(double));
    for (i9 = 0; i9 < kAcol; i9++) {
      qdd->data[i9] = 0.0;
    }

    m = eomLHS->size[0];
    u0 = eomLHS->size[0];
    mn = eomLHS->size[1];
    if (u0 <= mn) {
      mn = u0;
    }

    for (kAcol = 0; kAcol + 1 <= mn; kAcol++) {
      if (unusedU0->data[kAcol] != 0.0) {
        wj = eomRHS->data[kAcol];
        for (i = kAcol + 1; i + 1 <= m; i++) {
          wj += eomLHS->data[i + eomLHS->size[0] * kAcol] * eomRHS->data[i];
        }

        wj *= unusedU0->data[kAcol];
        if (wj != 0.0) {
          eomRHS->data[kAcol] -= wj;
          for (i = kAcol + 1; i + 1 <= m; i++) {
            eomRHS->data[i] -= eomLHS->data[i + eomLHS->size[0] * kAcol] * wj;
          }
        }
      }
    }

    for (i = 0; i + 1 <= loop_ub; i++) {
      qdd->data[jpvt->data[i] - 1] = eomRHS->data[i];
    }

    for (kAcol = loop_ub - 1; kAcol + 1 > 0; kAcol--) {
      qdd->data[jpvt->data[kAcol] - 1] /= eomLHS->data[kAcol + eomLHS->size[0] *
        kAcol];
      for (i = 0; i + 1 <= kAcol; i++) {
        qdd->data[jpvt->data[i] - 1] -= qdd->data[jpvt->data[kAcol] - 1] *
          eomLHS->data[i + eomLHS->size[0] * kAcol];
      }
    }
  }

  emxFree_int32_T(&jpvt);
  emxFree_real_T(&unusedU0);
  emxFree_real_T(&eomRHS);
  emxFree_real_T(&eomLHS);
  emxFree_real_T(&Mij);
}

/*
 * File trailer for computeQdd.c
 *
 * [EOF]
 */
