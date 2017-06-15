/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: getDk.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "getDk.h"
#include "MGH_qq.h"
#include "MGH_q.h"
#include "MGH.h"
#include "MMH_qq.h"
#include "MMH_q.h"
#include "MMH.h"
#include "any.h"
#include "MGP_qq.h"
#include "MGP_q.h"
#include "MGP.h"
#include "simulateDNA_emxutil.h"
#include "MGPm_qq.h"
#include "MGPm_q.h"
#include "MGPm.h"
#include "DNA2inc.h"
#include "sum.h"
#include "getCompoints.h"

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
 *                emxArray_real_T *D
 *                emxArray_real_T *Dq
 * Return Type  : void
 */
void b_getDk(double t, const emxArray_real_T *state, const emxArray_real_T
             *DNA_incstr, const emxArray_real_T *DNA_edgelabel, const
             emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
             emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar, const
             emxArray_real_T *DNA_Pmpar, emxArray_real_T *D, emxArray_real_T *Dq)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  int i7;
  int n;
  emxArray_boolean_T *c_DNA_edgelabel;
  double nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  double nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  double nPm;
  double nC;
  int idx;
  double anew;
  emxArray_real_T *X;
  double cnr;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  int ii;
  boolean_T exitg3;
  emxArray_real_T *cnrIdx;
  emxArray_int32_T *r10;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int massnr_data[100];
  boolean_T b_massnr_data[100];
  int massnr_size[1];
  boolean_T exitg1;
  emxArray_boolean_T c_massnr_data;
  boolean_T guard1 = false;
  boolean_T d_massnr_data[100];
  int b_massnr_size[1];
  emxArray_boolean_T e_massnr_data;
  double ndbl;
  boolean_T f_massnr_data[100];
  double b_X[6];
  double mx[3];
  int c_massnr_size[1];
  double b_comPoints[2];
  emxArray_boolean_T g_massnr_data;
  double b_mx[6];
  double c_comPoints[2];
  double dv0[3];
  double apnd;
  double cdiff;
  double u1;
  double MMHconstraintd[12];
  int iv0[3];
  emxInit_real_T(&comPoints, 2);
  emxInit_boolean_T(&b_DNA_edgelabel, 2);
  getCompoints(DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar, DNA_Ppar,
               DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  i7 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)b_DNA_edgelabel, i7, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i7 = 0; i7 < n; i7++) {
    b_DNA_edgelabel->data[i7] = (DNA_edgelabel->data[i7] == 1.0);
  }

  emxInit_boolean_T(&c_DNA_edgelabel, 2);
  nH = sum(b_DNA_edgelabel);

  /* Number of hinges */
  i7 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)c_DNA_edgelabel, i7, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i7 = 0; i7 < n; i7++) {
    c_DNA_edgelabel->data[i7] = (DNA_edgelabel->data[i7] == 3.0);
  }

  emxInit_boolean_T(&d_DNA_edgelabel, 2);
  nP = sum(c_DNA_edgelabel);
  i7 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)d_DNA_edgelabel, i7, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i7 = 0; i7 < n; i7++) {
    d_DNA_edgelabel->data[i7] = (DNA_edgelabel->data[i7] == 4.0);
  }

  emxInit_real_T(&incH, 2);
  emxInit_real_T(&incP, 2);
  emxInit_real_T(&incPm, 2);
  nPm = sum(d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  b_DNA2inc(DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  c_DNA2inc(DNA_incstr, DNA_edgelabel, incP);
  d_DNA2inc(DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  i7 = D->size[0];
  D->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)D, i7, (int)sizeof(double));
  n = (int)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (i7 = 0; i7 < n; i7++) {
    D->data[i7] = 0.0;
  }

  /* For scleronomic constraints */
  i7 = DNA_Mpar->size[0];
  idx = Dq->size[0] * Dq->size[1];
  Dq->size[0] = (int)nC;
  Dq->size[1] = (int)(((double)i7 - 1.0) * 3.0);
  emxEnsureCapacity((emxArray__common *)Dq, idx, (int)sizeof(double));
  n = (int)nC * (int)(((double)i7 - 1.0) * 3.0);
  for (i7 = 0; i7 < n; i7++) {
    Dq->data[i7] = 0.0;
  }

  /* Extra for rheonomic constraints */
  anew = (double)state->size[0] / 2.0;
  if (1.0 > anew) {
    n = 0;
  } else {
    n = (int)anew;
  }

  emxInit_real_T(&X, 2);
  i7 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = n;
  emxEnsureCapacity((emxArray__common *)X, i7, (int)sizeof(double));
  for (i7 = 0; i7 < n; i7++) {
    X->data[X->size[0] * i7] = state->data[i7];
  }

  /* For rotational joint */
  cnr = 1.0;
  for (k = 0; k < (int)nH; k++) {
    n = incH->size[0];
    for (i7 = 0; i7 < n; i7++) {
      x_data[i7] = (incH->data[i7 + incH->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= n)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i7 = 0; i7 < n; i7++) {
      massnr_data[i7] = ii_data[i7];
    }

    /* Find entries in column */
    massnr_size[0] = n;
    for (i7 = 0; i7 < n; i7++) {
      b_massnr_data[i7] = (massnr_data[i7] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    if (any(&c_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        mx[i7] = X->data[(int)(anew + (-2.0 + (double)i7)) - 1];
      }

      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      MGH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, *(double (*)[2])&D->data[(int)cnr - 1]);
      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      MGH_q(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            mx, b_X);
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        for (idx = 0; idx < 2; idx++) {
          Dq->data[((int)(cnr + (double)idx) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i7)) - 1)) - 1] = b_X[idx + (i7 << 1)];
        }
      }

      cnr += 2.0;
    } else {
      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        b_X[i7] = X->data[(int)(anew + (-2.0 + (double)i7)) - 1];
      }

      for (i7 = 0; i7 < 3; i7++) {
        b_X[i7 + 3] = X->data[(int)(ndbl + (-2.0 + (double)i7)) - 1];
      }

      for (i7 = 0; i7 < 6; i7++) {
        b_mx[i7] = b_X[i7];
      }

      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[0] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      for (i7 = 0; i7 < 2; i7++) {
        c_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      MMH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, *(double (*)[2])&D->data[(int)cnr - 1]);

      /* Constraints */
      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[0] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      for (i7 = 0; i7 < 2; i7++) {
        c_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      MMH_q(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            c_comPoints, b_mx, MMHconstraintd);

      /* Derivative of constraints */
      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        for (idx = 0; idx < 2; idx++) {
          Dq->data[((int)(cnr + (double)idx) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i7)) - 1)) - 1] = MMHconstraintd[idx + (i7 << 1)];
        }
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        for (idx = 0; idx < 2; idx++) {
          Dq->data[((int)(cnr + (double)idx) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i7)) - 1)) - 1] = MMHconstraintd[idx + ((3 + i7) << 1)];
        }
      }

      cnr += 2.0;
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  for (k = 0; k < (int)nP; k++) {
    n = incP->size[0];
    for (i7 = 0; i7 < n; i7++) {
      x_data[i7] = (incP->data[i7 + incP->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= n)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i7 = 0; i7 < n; i7++) {
      massnr_data[i7] = ii_data[i7];
    }

    /* Find entries in column */
    b_massnr_size[0] = n;
    for (i7 = 0; i7 < n; i7++) {
      d_massnr_data[i7] = (massnr_data[i7] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    if (any(&e_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        mx[i7] = X->data[(int)(anew + (-2.0 + (double)i7)) - 1];
      }

      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      D->data[(int)cnr - 1] = MGP(*(double (*)[2])&DNA_Ppar->data[DNA_Ppar->
        size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx);
      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      MGP_q(*(double (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] * k],
            DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx, dv0);
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        Dq->data[((int)cnr + Dq->size[0] * ((int)(anew + (-2.0 + (double)i7)) -
                   1)) - 1] = dv0[i7];
      }

      cnr++;
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  k = 0;
  emxInit_real_T(&cnrIdx, 2);
  emxInit_int32_T(&r10, 1);
  while (k <= (int)nPm - 1) {
    n = incPm->size[0];
    for (i7 = 0; i7 < n; i7++) {
      x_data[i7] = (incPm->data[i7 + incPm->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= n)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i7 = 0; i7 < n; i7++) {
      massnr_data[i7] = ii_data[i7];
    }

    /* Find entries in column */
    c_massnr_size[0] = n;
    for (i7 = 0; i7 < n; i7++) {
      f_massnr_data[i7] = (massnr_data[i7] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    if (any(&g_massnr_data)) {
      /* If this column contains ground */
      /*          keyboard  */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        mx[i7] = X->data[(int)(anew + (-2.0 + (double)i7)) - 1];
      }

      if (cnr + 1.0 < cnr) {
        n = 0;
        anew = cnr;
        apnd = cnr + 1.0;
      } else if (rtIsInf(cnr) || rtIsInf(cnr + 1.0)) {
        n = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
      } else {
        anew = cnr;
        ndbl = floor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        u1 = cnr + 1.0;
        if (anew >= u1) {
          u1 = anew;
        }

        if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          n = (int)ndbl;
        } else {
          n = 0;
        }
      }

      i7 = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = n;
      emxEnsureCapacity((emxArray__common *)cnrIdx, i7, (int)sizeof(double));
      if (n > 0) {
        cnrIdx->data[0] = anew;
        if (n > 1) {
          cnrIdx->data[n - 1] = apnd;
          idx = (n - 1) / 2;
          for (ii = 1; ii < idx; ii++) {
            cnrIdx->data[ii] = anew + (double)ii;
            cnrIdx->data[(n - ii) - 1] = apnd - (double)ii;
          }

          if (idx << 1 == n - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (double)idx;
            cnrIdx->data[idx + 1] = apnd - (double)idx;
          }
        }
      }

      /*           keyboard  */
      i7 = r10->size[0];
      r10->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r10, i7, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i7 = 0; i7 < n; i7++) {
        r10->data[i7] = (int)cnrIdx->data[cnrIdx->size[0] * i7] - 1;
      }

      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      MGPm(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, c_comPoints);
      ii = r10->size[0];
      for (i7 = 0; i7 < ii; i7++) {
        D->data[r10->data[i7]] = c_comPoints[i7];
      }

      i7 = r10->size[0];
      r10->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r10, i7, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i7 = 0; i7 < n; i7++) {
        r10->data[i7] = (int)cnrIdx->data[cnrIdx->size[0] * i7] - 1;
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i7 = 0; i7 < 3; i7++) {
        iv0[i7] = (int)(anew + (-2.0 + (double)i7)) - 1;
      }

      for (i7 = 0; i7 < 2; i7++) {
        b_comPoints[i7] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i7) - 1];
      }

      MGPm_q(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
             DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, b_X);
      ii = r10->size[0];
      for (i7 = 0; i7 < 3; i7++) {
        for (idx = 0; idx < ii; idx++) {
          Dq->data[r10->data[idx] + Dq->size[0] * iv0[i7]] = b_X[idx + ii * i7];
        }
      }

      /*  keyboard  */
      cnr += 2.0;
    }

    k++;
  }

  emxFree_int32_T(&r10);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
}

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
 *                emxArray_real_T *D
 *                emxArray_real_T *Dq
 *                emxArray_real_T *Dqq
 *                emxArray_real_T *Dt
 * Return Type  : void
 */
void c_getDk(double t, const emxArray_real_T *state, const emxArray_real_T
             *DNA_incstr, const emxArray_real_T *DNA_edgelabel, const
             emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
             emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar, const
             emxArray_real_T *DNA_Pmpar, emxArray_real_T *D, emxArray_real_T *Dq,
             emxArray_real_T *Dqq, emxArray_real_T *Dt)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  int i8;
  int n;
  emxArray_boolean_T *c_DNA_edgelabel;
  double nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  double nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  double nPm;
  double nC;
  int ii;
  double anew;
  emxArray_real_T *X;
  emxArray_real_T *Xd;
  int idx;
  double cnr;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  boolean_T exitg3;
  emxArray_real_T *cnrIdx;
  emxArray_int32_T *r11;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int massnr_data[100];
  boolean_T b_massnr_data[100];
  int massnr_size[1];
  boolean_T exitg1;
  emxArray_boolean_T c_massnr_data;
  boolean_T guard1 = false;
  boolean_T d_massnr_data[100];
  int b_massnr_size[1];
  emxArray_boolean_T e_massnr_data;
  double ndbl;
  boolean_T f_massnr_data[100];
  double b_X[6];
  double mx[3];
  int c_massnr_size[1];
  emxArray_boolean_T g_massnr_data;
  double mxd[3];
  double b_mx[6];
  double b_comPoints[2];
  double b_mxd[6];
  double dv1[3];
  double c_comPoints[2];
  double apnd;
  double cdiff;
  double u1;
  double MMHconstraintd[12];
  int iv1[3];
  double dv2[2];
  emxInit_real_T(&comPoints, 2);
  emxInit_boolean_T(&b_DNA_edgelabel, 2);
  getCompoints(DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar, DNA_Ppar,
               DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  i8 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)b_DNA_edgelabel, i8, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i8 = 0; i8 < n; i8++) {
    b_DNA_edgelabel->data[i8] = (DNA_edgelabel->data[i8] == 1.0);
  }

  emxInit_boolean_T(&c_DNA_edgelabel, 2);
  nH = sum(b_DNA_edgelabel);

  /* Number of hinges */
  i8 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)c_DNA_edgelabel, i8, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i8 = 0; i8 < n; i8++) {
    c_DNA_edgelabel->data[i8] = (DNA_edgelabel->data[i8] == 3.0);
  }

  emxInit_boolean_T(&d_DNA_edgelabel, 2);
  nP = sum(c_DNA_edgelabel);
  i8 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)d_DNA_edgelabel, i8, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i8 = 0; i8 < n; i8++) {
    d_DNA_edgelabel->data[i8] = (DNA_edgelabel->data[i8] == 4.0);
  }

  emxInit_real_T(&incH, 2);
  emxInit_real_T(&incP, 2);
  emxInit_real_T(&incPm, 2);
  nPm = sum(d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  b_DNA2inc(DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  c_DNA2inc(DNA_incstr, DNA_edgelabel, incP);
  d_DNA2inc(DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  i8 = D->size[0];
  D->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)D, i8, (int)sizeof(double));
  n = (int)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (i8 = 0; i8 < n; i8++) {
    D->data[i8] = 0.0;
  }

  /* For scleronomic constraints */
  i8 = DNA_Mpar->size[0];
  ii = Dq->size[0] * Dq->size[1];
  Dq->size[0] = (int)nC;
  Dq->size[1] = (int)(((double)i8 - 1.0) * 3.0);
  emxEnsureCapacity((emxArray__common *)Dq, ii, (int)sizeof(double));
  n = (int)nC * (int)(((double)i8 - 1.0) * 3.0);
  for (i8 = 0; i8 < n; i8++) {
    Dq->data[i8] = 0.0;
  }

  i8 = Dqq->size[0];
  Dqq->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)Dqq, i8, (int)sizeof(double));
  n = (int)nC;
  for (i8 = 0; i8 < n; i8++) {
    Dqq->data[i8] = 0.0;
  }

  i8 = Dt->size[0];
  Dt->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)Dt, i8, (int)sizeof(double));
  n = (int)nC;
  for (i8 = 0; i8 < n; i8++) {
    Dt->data[i8] = 0.0;
  }

  /* Extra for rheonomic constraints */
  anew = (double)state->size[0] / 2.0;
  if (1.0 > anew) {
    n = 0;
  } else {
    n = (int)anew;
  }

  emxInit_real_T(&X, 2);
  i8 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = n;
  emxEnsureCapacity((emxArray__common *)X, i8, (int)sizeof(double));
  for (i8 = 0; i8 < n; i8++) {
    X->data[X->size[0] * i8] = state->data[i8];
  }

  anew = (double)state->size[0] / 2.0;
  if (anew + 1.0 > state->size[0]) {
    i8 = 0;
    ii = 0;
  } else {
    i8 = (int)(anew + 1.0) - 1;
    ii = state->size[0];
  }

  emxInit_real_T(&Xd, 2);
  idx = Xd->size[0] * Xd->size[1];
  Xd->size[0] = 1;
  Xd->size[1] = ii - i8;
  emxEnsureCapacity((emxArray__common *)Xd, idx, (int)sizeof(double));
  n = ii - i8;
  for (ii = 0; ii < n; ii++) {
    Xd->data[Xd->size[0] * ii] = state->data[i8 + ii];
  }

  /* For rotational joint */
  cnr = 1.0;
  for (k = 0; k < (int)nH; k++) {
    n = incH->size[0];
    for (i8 = 0; i8 < n; i8++) {
      x_data[i8] = (incH->data[i8 + incH->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= n)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i8 = 0; i8 < n; i8++) {
      massnr_data[i8] = ii_data[i8];
    }

    /* Find entries in column */
    massnr_size[0] = n;
    for (i8 = 0; i8 < n; i8++) {
      b_massnr_data[i8] = (massnr_data[i8] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    if (any(&c_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        mx[i8] = X->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        mxd[i8] = Xd->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MGH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, *(double (*)[2])&D->data[(int)cnr - 1]);
      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MGH_q(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            mx, b_X);
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        for (ii = 0; ii < 2; ii++) {
          Dq->data[((int)(cnr + (double)ii) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i8)) - 1)) - 1] = b_X[ii + (i8 << 1)];
        }
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MGH_qq(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             mx, mxd, *(double (*)[2])&Dqq->data[(int)cnr - 1]);
      cnr += 2.0;
    } else {
      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        b_X[i8] = X->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      for (i8 = 0; i8 < 3; i8++) {
        b_X[i8 + 3] = X->data[(int)(ndbl + (-2.0 + (double)i8)) - 1];
      }

      for (i8 = 0; i8 < 6; i8++) {
        b_mx[i8] = b_X[i8];
      }

      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        b_X[i8] = Xd->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      for (i8 = 0; i8 < 3; i8++) {
        b_X[i8 + 3] = Xd->data[(int)(ndbl + (-2.0 + (double)i8)) - 1];
      }

      for (i8 = 0; i8 < 6; i8++) {
        b_mxd[i8] = b_X[i8];
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[0] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      for (i8 = 0; i8 < 2; i8++) {
        c_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MMH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, *(double (*)[2])&D->data[(int)cnr - 1]);

      /* Constraints */
      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[0] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      for (i8 = 0; i8 < 2; i8++) {
        c_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MMH_q(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            c_comPoints, b_mx, MMHconstraintd);

      /* Derivative of constraints */
      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        for (ii = 0; ii < 2; ii++) {
          Dq->data[((int)(cnr + (double)ii) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i8)) - 1)) - 1] = MMHconstraintd[ii + (i8 << 1)];
        }
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        for (ii = 0; ii < 2; ii++) {
          Dq->data[((int)(cnr + (double)ii) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i8)) - 1)) - 1] = MMHconstraintd[ii + ((3 + i8) << 1)];
        }
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[0] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      for (i8 = 0; i8 < 2; i8++) {
        c_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MMH_qq(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             c_comPoints, b_mx, b_mxd, *(double (*)[2])&Dqq->data[(int)cnr - 1]);

      /* Double derivative of constraints */
      cnr += 2.0;
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  for (k = 0; k < (int)nP; k++) {
    n = incP->size[0];
    for (i8 = 0; i8 < n; i8++) {
      x_data[i8] = (incP->data[i8 + incP->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= n)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i8 = 0; i8 < n; i8++) {
      massnr_data[i8] = ii_data[i8];
    }

    /* Find entries in column */
    b_massnr_size[0] = n;
    for (i8 = 0; i8 < n; i8++) {
      d_massnr_data[i8] = (massnr_data[i8] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    if (any(&e_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        mx[i8] = X->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        mxd[i8] = Xd->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      D->data[(int)cnr - 1] = MGP(*(double (*)[2])&DNA_Ppar->data[DNA_Ppar->
        size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx);
      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MGP_q(*(double (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] * k],
            DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx, dv1);
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        Dq->data[((int)cnr + Dq->size[0] * ((int)(anew + (-2.0 + (double)i8)) -
                   1)) - 1] = dv1[i8];
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      Dqq->data[(int)cnr - 1] = MGP_qq(*(double (*)[2])&DNA_Ppar->data
        [DNA_Ppar->size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k],
        b_comPoints, mx, mxd);
      cnr++;
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  k = 0;
  emxInit_real_T(&cnrIdx, 2);
  emxInit_int32_T(&r11, 1);
  while (k <= (int)nPm - 1) {
    n = incPm->size[0];
    for (i8 = 0; i8 < n; i8++) {
      x_data[i8] = (incPm->data[i8 + incPm->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= n)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i8 = 0; i8 < n; i8++) {
      massnr_data[i8] = ii_data[i8];
    }

    /* Find entries in column */
    c_massnr_size[0] = n;
    for (i8 = 0; i8 < n; i8++) {
      f_massnr_data[i8] = (massnr_data[i8] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    if (any(&g_massnr_data)) {
      /* If this column contains ground */
      /*          keyboard  */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        mx[i8] = X->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        mxd[i8] = Xd->data[(int)(anew + (-2.0 + (double)i8)) - 1];
      }

      if (cnr + 1.0 < cnr) {
        n = 0;
        anew = cnr;
        apnd = cnr + 1.0;
      } else if (rtIsInf(cnr) || rtIsInf(cnr + 1.0)) {
        n = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
      } else {
        anew = cnr;
        ndbl = floor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        u1 = cnr + 1.0;
        if (anew >= u1) {
          u1 = anew;
        }

        if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          n = (int)ndbl;
        } else {
          n = 0;
        }
      }

      i8 = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = n;
      emxEnsureCapacity((emxArray__common *)cnrIdx, i8, (int)sizeof(double));
      if (n > 0) {
        cnrIdx->data[0] = anew;
        if (n > 1) {
          cnrIdx->data[n - 1] = apnd;
          idx = (n - 1) / 2;
          for (ii = 1; ii < idx; ii++) {
            cnrIdx->data[ii] = anew + (double)ii;
            cnrIdx->data[(n - ii) - 1] = apnd - (double)ii;
          }

          if (idx << 1 == n - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (double)idx;
            cnrIdx->data[idx + 1] = apnd - (double)idx;
          }
        }
      }

      /*           keyboard  */
      i8 = r11->size[0];
      r11->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r11, i8, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i8 = 0; i8 < n; i8++) {
        r11->data[i8] = (int)cnrIdx->data[cnrIdx->size[0] * i8] - 1;
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MGPm(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, c_comPoints);
      idx = r11->size[0];
      for (i8 = 0; i8 < idx; i8++) {
        D->data[r11->data[i8]] = c_comPoints[i8];
      }

      i8 = r11->size[0];
      r11->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r11, i8, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i8 = 0; i8 < n; i8++) {
        r11->data[i8] = (int)cnrIdx->data[cnrIdx->size[0] * i8] - 1;
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i8 = 0; i8 < 3; i8++) {
        iv1[i8] = (int)(anew + (-2.0 + (double)i8)) - 1;
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MGPm_q(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
             DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, b_X);
      idx = r11->size[0];
      for (i8 = 0; i8 < 3; i8++) {
        for (ii = 0; ii < idx; ii++) {
          Dq->data[r11->data[ii] + Dq->size[0] * iv1[i8]] = b_X[ii + idx * i8];
        }
      }

      i8 = r11->size[0];
      r11->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r11, i8, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i8 = 0; i8 < n; i8++) {
        r11->data[i8] = (int)cnrIdx->data[cnrIdx->size[0] * i8] - 1;
      }

      for (i8 = 0; i8 < 2; i8++) {
        b_comPoints[i8] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * i8) - 1];
      }

      MGPm_qq(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
              DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, mxd,
              c_comPoints);
      idx = r11->size[0];
      for (i8 = 0; i8 < idx; i8++) {
        Dqq->data[r11->data[i8]] = c_comPoints[i8];
      }

      i8 = r11->size[0];
      r11->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r11, i8, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i8 = 0; i8 < n; i8++) {
        r11->data[i8] = (int)cnrIdx->data[cnrIdx->size[0] * i8] - 1;
      }

      /* MGPM_T */
      /*     C4_T = MGPM_T(IN1,ALPHA,A,W,IN5,T,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     04-Jul-2016 16:03:30 */
      dv2[0] = 0.0;
      dv2[1] = DNA_Pmpar->data[3 + DNA_Pmpar->size[0] * k] * DNA_Pmpar->data[4 +
        DNA_Pmpar->size[0] * k] * cos(t * DNA_Pmpar->data[4 + DNA_Pmpar->size[0]
        * k]);
      idx = r11->size[0];
      for (i8 = 0; i8 < idx; i8++) {
        Dt->data[r11->data[i8]] = dv2[i8];
      }

      /*  keyboard  */
      cnr += 2.0;
    }

    k++;
  }

  emxFree_int32_T(&r11);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&Xd);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
}

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
 *                emxArray_real_T *D
 *                emxArray_real_T *Dq
 *                emxArray_real_T *Dqq
 *                emxArray_real_T *Dt
 *                emxArray_real_T *Dqt
 *                emxArray_real_T *Dtt
 * Return Type  : void
 */
void d_getDk(double t, const emxArray_real_T *state, const emxArray_real_T
             *DNA_incstr, const emxArray_real_T *DNA_edgelabel, const
             emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
             emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar, const
             emxArray_real_T *DNA_Pmpar, emxArray_real_T *D, emxArray_real_T *Dq,
             emxArray_real_T *Dqq, emxArray_real_T *Dt, emxArray_real_T *Dqt,
             emxArray_real_T *Dtt)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  int i12;
  int n;
  emxArray_boolean_T *c_DNA_edgelabel;
  double nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  double nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  double nPm;
  double nC;
  int ii;
  double anew;
  emxArray_real_T *X;
  emxArray_real_T *Xd;
  int idx;
  double cnr;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  boolean_T exitg3;
  emxArray_real_T *cnrIdx;
  emxArray_int32_T *r12;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int massnr_data[100];
  boolean_T b_massnr_data[100];
  int massnr_size[1];
  boolean_T exitg1;
  emxArray_boolean_T c_massnr_data;
  boolean_T guard1 = false;
  boolean_T d_massnr_data[100];
  int b_massnr_size[1];
  emxArray_boolean_T e_massnr_data;
  double ndbl;
  boolean_T f_massnr_data[100];
  double b_X[6];
  double mx[3];
  int c_massnr_size[1];
  emxArray_boolean_T g_massnr_data;
  double mxd[3];
  double b_mx[6];
  double b_comPoints[2];
  double b_mxd[6];
  double dv3[3];
  double c_comPoints[2];
  double apnd;
  double cdiff;
  double u1;
  double MMHconstraintd[12];
  int iv2[3];
  double dv4[2];
  double dv5[2];
  emxInit_real_T(&comPoints, 2);
  emxInit_boolean_T(&b_DNA_edgelabel, 2);
  getCompoints(DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar, DNA_Ppar,
               DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  i12 = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)b_DNA_edgelabel, i12, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (i12 = 0; i12 < n; i12++) {
    b_DNA_edgelabel->data[i12] = (DNA_edgelabel->data[i12] == 1.0);
  }

  emxInit_boolean_T(&c_DNA_edgelabel, 2);
  nH = sum(b_DNA_edgelabel);

  /* Number of hinges */
  i12 = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)c_DNA_edgelabel, i12, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (i12 = 0; i12 < n; i12++) {
    c_DNA_edgelabel->data[i12] = (DNA_edgelabel->data[i12] == 3.0);
  }

  emxInit_boolean_T(&d_DNA_edgelabel, 2);
  nP = sum(c_DNA_edgelabel);
  i12 = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)d_DNA_edgelabel, i12, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (i12 = 0; i12 < n; i12++) {
    d_DNA_edgelabel->data[i12] = (DNA_edgelabel->data[i12] == 4.0);
  }

  emxInit_real_T(&incH, 2);
  emxInit_real_T(&incP, 2);
  emxInit_real_T(&incPm, 2);
  nPm = sum(d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  b_DNA2inc(DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  c_DNA2inc(DNA_incstr, DNA_edgelabel, incP);
  d_DNA2inc(DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  i12 = D->size[0];
  D->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)D, i12, (int)sizeof(double));
  n = (int)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (i12 = 0; i12 < n; i12++) {
    D->data[i12] = 0.0;
  }

  /* For scleronomic constraints */
  i12 = DNA_Mpar->size[0];
  ii = Dq->size[0] * Dq->size[1];
  Dq->size[0] = (int)nC;
  Dq->size[1] = (int)(((double)i12 - 1.0) * 3.0);
  emxEnsureCapacity((emxArray__common *)Dq, ii, (int)sizeof(double));
  n = (int)nC * (int)(((double)i12 - 1.0) * 3.0);
  for (i12 = 0; i12 < n; i12++) {
    Dq->data[i12] = 0.0;
  }

  i12 = Dqq->size[0];
  Dqq->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)Dqq, i12, (int)sizeof(double));
  n = (int)nC;
  for (i12 = 0; i12 < n; i12++) {
    Dqq->data[i12] = 0.0;
  }

  i12 = Dt->size[0];
  Dt->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)Dt, i12, (int)sizeof(double));
  n = (int)nC;
  for (i12 = 0; i12 < n; i12++) {
    Dt->data[i12] = 0.0;
  }

  /* Extra for rheonomic constraints */
  i12 = Dqt->size[0];
  Dqt->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)Dqt, i12, (int)sizeof(double));
  n = (int)nC;
  for (i12 = 0; i12 < n; i12++) {
    Dqt->data[i12] = 0.0;
  }

  i12 = Dtt->size[0];
  Dtt->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)Dtt, i12, (int)sizeof(double));
  n = (int)nC;
  for (i12 = 0; i12 < n; i12++) {
    Dtt->data[i12] = 0.0;
  }

  anew = (double)state->size[0] / 2.0;
  if (1.0 > anew) {
    n = 0;
  } else {
    n = (int)anew;
  }

  emxInit_real_T(&X, 2);
  i12 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = n;
  emxEnsureCapacity((emxArray__common *)X, i12, (int)sizeof(double));
  for (i12 = 0; i12 < n; i12++) {
    X->data[X->size[0] * i12] = state->data[i12];
  }

  anew = (double)state->size[0] / 2.0;
  if (anew + 1.0 > state->size[0]) {
    i12 = 0;
    ii = 0;
  } else {
    i12 = (int)(anew + 1.0) - 1;
    ii = state->size[0];
  }

  emxInit_real_T(&Xd, 2);
  idx = Xd->size[0] * Xd->size[1];
  Xd->size[0] = 1;
  Xd->size[1] = ii - i12;
  emxEnsureCapacity((emxArray__common *)Xd, idx, (int)sizeof(double));
  n = ii - i12;
  for (ii = 0; ii < n; ii++) {
    Xd->data[Xd->size[0] * ii] = state->data[i12 + ii];
  }

  /* For rotational joint */
  cnr = 1.0;
  for (k = 0; k < (int)nH; k++) {
    n = incH->size[0];
    for (i12 = 0; i12 < n; i12++) {
      x_data[i12] = (incH->data[i12 + incH->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= n)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i12 = 0; i12 < n; i12++) {
      massnr_data[i12] = ii_data[i12];
    }

    /* Find entries in column */
    massnr_size[0] = n;
    for (i12 = 0; i12 < n; i12++) {
      b_massnr_data[i12] = (massnr_data[i12] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    if (any(&c_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        mx[i12] = X->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        mxd[i12] = Xd->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MGH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, *(double (*)[2])&D->data[(int)cnr - 1]);
      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MGH_q(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            mx, b_X);
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        for (ii = 0; ii < 2; ii++) {
          Dq->data[((int)(cnr + (double)ii) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i12)) - 1)) - 1] = b_X[ii + (i12 << 1)];
        }
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MGH_qq(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             mx, mxd, *(double (*)[2])&Dqq->data[(int)cnr - 1]);
      cnr += 2.0;
    } else {
      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        b_X[i12] = X->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      for (i12 = 0; i12 < 3; i12++) {
        b_X[i12 + 3] = X->data[(int)(ndbl + (-2.0 + (double)i12)) - 1];
      }

      for (i12 = 0; i12 < 6; i12++) {
        b_mx[i12] = b_X[i12];
      }

      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        b_X[i12] = Xd->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      for (i12 = 0; i12 < 3; i12++) {
        b_X[i12 + 3] = Xd->data[(int)(ndbl + (-2.0 + (double)i12)) - 1];
      }

      for (i12 = 0; i12 < 6; i12++) {
        b_mxd[i12] = b_X[i12];
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[0] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      for (i12 = 0; i12 < 2; i12++) {
        c_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MMH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, *(double (*)[2])&D->data[(int)cnr - 1]);

      /* Constraints */
      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[0] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      for (i12 = 0; i12 < 2; i12++) {
        c_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MMH_q(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
            c_comPoints, b_mx, MMHconstraintd);

      /* Derivative of constraints */
      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        for (ii = 0; ii < 2; ii++) {
          Dq->data[((int)(cnr + (double)ii) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i12)) - 1)) - 1] = MMHconstraintd[ii + (i12 << 1)];
        }
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        for (ii = 0; ii < 2; ii++) {
          Dq->data[((int)(cnr + (double)ii) + Dq->size[0] * ((int)(anew + (-2.0
            + (double)i12)) - 1)) - 1] = MMHconstraintd[ii + ((3 + i12) << 1)];
        }
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[0] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      for (i12 = 0; i12 < 2; i12++) {
        c_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MMH_qq(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
             c_comPoints, b_mx, b_mxd, *(double (*)[2])&Dqq->data[(int)cnr - 1]);

      /* Double derivative of constraints */
      cnr += 2.0;
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  for (k = 0; k < (int)nP; k++) {
    n = incP->size[0];
    for (i12 = 0; i12 < n; i12++) {
      x_data[i12] = (incP->data[i12 + incP->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= n)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i12 = 0; i12 < n; i12++) {
      massnr_data[i12] = ii_data[i12];
    }

    /* Find entries in column */
    b_massnr_size[0] = n;
    for (i12 = 0; i12 < n; i12++) {
      d_massnr_data[i12] = (massnr_data[i12] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    if (any(&e_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        mx[i12] = X->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        mxd[i12] = Xd->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      D->data[(int)cnr - 1] = MGP(*(double (*)[2])&DNA_Ppar->data[DNA_Ppar->
        size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx);
      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MGP_q(*(double (*)[2])&DNA_Ppar->data[DNA_Ppar->size[0] * k],
            DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx, dv3);
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        Dq->data[((int)cnr + Dq->size[0] * ((int)(anew + (-2.0 + (double)i12)) -
                   1)) - 1] = dv3[i12];
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      Dqq->data[(int)cnr - 1] = MGP_qq(*(double (*)[2])&DNA_Ppar->data
        [DNA_Ppar->size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k],
        b_comPoints, mx, mxd);
      cnr++;
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  k = 0;
  emxInit_real_T(&cnrIdx, 2);
  emxInit_int32_T(&r12, 1);
  while (k <= (int)nPm - 1) {
    n = incPm->size[0];
    for (i12 = 0; i12 < n; i12++) {
      x_data[i12] = (incPm->data[i12 + incPm->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= n)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (i12 = 0; i12 < n; i12++) {
      massnr_data[i12] = ii_data[i12];
    }

    /* Find entries in column */
    c_massnr_size[0] = n;
    for (i12 = 0; i12 < n; i12++) {
      f_massnr_data[i12] = (massnr_data[i12] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    if (any(&g_massnr_data)) {
      /* If this column contains ground */
      /*          keyboard  */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        mx[i12] = X->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        mxd[i12] = Xd->data[(int)(anew + (-2.0 + (double)i12)) - 1];
      }

      if (cnr + 1.0 < cnr) {
        n = 0;
        anew = cnr;
        apnd = cnr + 1.0;
      } else if (rtIsInf(cnr) || rtIsInf(cnr + 1.0)) {
        n = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
      } else {
        anew = cnr;
        ndbl = floor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        u1 = cnr + 1.0;
        if (anew >= u1) {
          u1 = anew;
        }

        if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          n = (int)ndbl;
        } else {
          n = 0;
        }
      }

      i12 = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = n;
      emxEnsureCapacity((emxArray__common *)cnrIdx, i12, (int)sizeof(double));
      if (n > 0) {
        cnrIdx->data[0] = anew;
        if (n > 1) {
          cnrIdx->data[n - 1] = apnd;
          idx = (n - 1) / 2;
          for (ii = 1; ii < idx; ii++) {
            cnrIdx->data[ii] = anew + (double)ii;
            cnrIdx->data[(n - ii) - 1] = apnd - (double)ii;
          }

          if (idx << 1 == n - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (double)idx;
            cnrIdx->data[idx + 1] = apnd - (double)idx;
          }
        }
      }

      /*           keyboard  */
      i12 = r12->size[0];
      r12->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i12, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i12 = 0; i12 < n; i12++) {
        r12->data[i12] = (int)cnrIdx->data[cnrIdx->size[0] * i12] - 1;
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MGPm(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, c_comPoints);
      idx = r12->size[0];
      for (i12 = 0; i12 < idx; i12++) {
        D->data[r12->data[i12]] = c_comPoints[i12];
      }

      i12 = r12->size[0];
      r12->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i12, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i12 = 0; i12 < n; i12++) {
        r12->data[i12] = (int)cnrIdx->data[cnrIdx->size[0] * i12] - 1;
      }

      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (i12 = 0; i12 < 3; i12++) {
        iv2[i12] = (int)(anew + (-2.0 + (double)i12)) - 1;
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MGPm_q(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
             DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, b_X);
      idx = r12->size[0];
      for (i12 = 0; i12 < 3; i12++) {
        for (ii = 0; ii < idx; ii++) {
          Dq->data[r12->data[ii] + Dq->size[0] * iv2[i12]] = b_X[ii + idx * i12];
        }
      }

      i12 = r12->size[0];
      r12->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i12, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i12 = 0; i12 < n; i12++) {
        r12->data[i12] = (int)cnrIdx->data[cnrIdx->size[0] * i12] - 1;
      }

      for (i12 = 0; i12 < 2; i12++) {
        b_comPoints[i12] = comPoints->data[((int)((double)massnr_data[1] - 1.0)
          + comPoints->size[0] * i12) - 1];
      }

      MGPm_qq(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
              DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], b_comPoints, mx, mxd,
              c_comPoints);
      idx = r12->size[0];
      for (i12 = 0; i12 < idx; i12++) {
        Dqq->data[r12->data[i12]] = c_comPoints[i12];
      }

      i12 = r12->size[0];
      r12->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i12, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i12 = 0; i12 < n; i12++) {
        r12->data[i12] = (int)cnrIdx->data[cnrIdx->size[0] * i12] - 1;
      }

      /* MGPM_T */
      /*     C4_T = MGPM_T(IN1,ALPHA,A,W,IN5,T,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     04-Jul-2016 16:03:30 */
      dv4[0] = 0.0;
      dv4[1] = DNA_Pmpar->data[3 + DNA_Pmpar->size[0] * k] * DNA_Pmpar->data[4 +
        DNA_Pmpar->size[0] * k] * cos(t * DNA_Pmpar->data[4 + DNA_Pmpar->size[0]
        * k]);
      idx = r12->size[0];
      for (i12 = 0; i12 < idx; i12++) {
        Dt->data[r12->data[i12]] = dv4[i12];
      }

      i12 = r12->size[0];
      r12->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i12, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i12 = 0; i12 < n; i12++) {
        r12->data[i12] = (int)cnrIdx->data[cnrIdx->size[0] * i12] - 1;
      }

      idx = r12->size[0];
      for (i12 = 0; i12 < idx; i12++) {
        Dqt->data[r12->data[i12]] = 0.0;
      }

      i12 = r12->size[0];
      r12->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i12, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (i12 = 0; i12 < n; i12++) {
        r12->data[i12] = (int)cnrIdx->data[cnrIdx->size[0] * i12] - 1;
      }

      /* MGPM_TT */
      /*     C4_TT = MGPM_TT(IN1,ALPHA,A,W,IN5,T,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     04-Jul-2016 16:03:30 */
      dv5[0] = 0.0;
      dv5[1] = -DNA_Pmpar->data[3 + DNA_Pmpar->size[0] * k] * (DNA_Pmpar->data[4
        + DNA_Pmpar->size[0] * k] * DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k])
        * sin(t * DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k]);
      idx = r12->size[0];
      for (i12 = 0; i12 < idx; i12++) {
        Dtt->data[r12->data[i12]] = dv5[i12];
      }

      /*  keyboard  */
      cnr += 2.0;
    }

    k++;
  }

  emxFree_int32_T(&r12);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&Xd);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
}

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
 *                emxArray_real_T *D
 * Return Type  : void
 */
void getDk(double t, const emxArray_real_T *state, const emxArray_real_T
           *DNA_incstr, const emxArray_real_T *DNA_edgelabel, const
           emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
           emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar, const
           emxArray_real_T *DNA_Pmpar, emxArray_real_T *D)
{
  emxArray_real_T *comPoints;
  emxArray_boolean_T *b_DNA_edgelabel;
  int ii;
  int n;
  emxArray_boolean_T *c_DNA_edgelabel;
  double nH;
  emxArray_boolean_T *d_DNA_edgelabel;
  double nP;
  emxArray_real_T *incH;
  emxArray_real_T *incP;
  emxArray_real_T *incPm;
  double nPm;
  double nC;
  double anew;
  emxArray_real_T *X;
  double cnr;
  int k;
  int idx;
  boolean_T x_data[100];
  int ii_data[100];
  boolean_T exitg3;
  emxArray_real_T *cnrIdx;
  emxArray_int32_T *r6;
  boolean_T guard3 = false;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int massnr_data[100];
  boolean_T b_massnr_data[100];
  int massnr_size[1];
  boolean_T exitg1;
  emxArray_boolean_T c_massnr_data;
  boolean_T guard1 = false;
  boolean_T d_massnr_data[100];
  int b_massnr_size[1];
  emxArray_boolean_T e_massnr_data;
  double ndbl;
  boolean_T f_massnr_data[100];
  double b_X[6];
  double mx[3];
  int c_massnr_size[1];
  double b_comPoints[2];
  emxArray_boolean_T g_massnr_data;
  double b_mx[6];
  double c_comPoints[2];
  double apnd;
  double cdiff;
  double u1;
  emxInit_real_T(&comPoints, 2);
  emxInit_boolean_T(&b_DNA_edgelabel, 2);
  getCompoints(DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar, DNA_Ppar,
               DNA_Pmpar, comPoints);

  /* Get the centre of mass points */
  /* Number of masses */
  ii = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)b_DNA_edgelabel, ii, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (ii = 0; ii < n; ii++) {
    b_DNA_edgelabel->data[ii] = (DNA_edgelabel->data[ii] == 1.0);
  }

  emxInit_boolean_T(&c_DNA_edgelabel, 2);
  nH = sum(b_DNA_edgelabel);

  /* Number of hinges */
  ii = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)c_DNA_edgelabel, ii, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (ii = 0; ii < n; ii++) {
    c_DNA_edgelabel->data[ii] = (DNA_edgelabel->data[ii] == 3.0);
  }

  emxInit_boolean_T(&d_DNA_edgelabel, 2);
  nP = sum(c_DNA_edgelabel);
  ii = d_DNA_edgelabel->size[0] * d_DNA_edgelabel->size[1];
  d_DNA_edgelabel->size[0] = 1;
  d_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)d_DNA_edgelabel, ii, (int)sizeof
                    (boolean_T));
  n = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (ii = 0; ii < n; ii++) {
    d_DNA_edgelabel->data[ii] = (DNA_edgelabel->data[ii] == 4.0);
  }

  emxInit_real_T(&incH, 2);
  emxInit_real_T(&incP, 2);
  emxInit_real_T(&incPm, 2);
  nPm = sum(d_DNA_edgelabel);

  /* If you are going to mex simulateDNA you should uncomment the next line, */
  /* and comment the line above. */
  b_DNA2inc(DNA_incstr, DNA_edgelabel, incH);

  /* Get incidence matrix */
  c_DNA2inc(DNA_incstr, DNA_edgelabel, incP);
  d_DNA2inc(DNA_incstr, DNA_edgelabel, incPm);
  nC = (nH * 2.0 + nP) + nPm * 2.0;

  /* The number of constraints */
  ii = D->size[0];
  D->size[0] = (int)nC;
  emxEnsureCapacity((emxArray__common *)D, ii, (int)sizeof(double));
  n = (int)nC;
  emxFree_boolean_T(&d_DNA_edgelabel);
  for (ii = 0; ii < n; ii++) {
    D->data[ii] = 0.0;
  }

  /* For scleronomic constraints */
  /* Extra for rheonomic constraints */
  anew = (double)state->size[0] / 2.0;
  if (1.0 > anew) {
    n = 0;
  } else {
    n = (int)anew;
  }

  emxInit_real_T(&X, 2);
  ii = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = n;
  emxEnsureCapacity((emxArray__common *)X, ii, (int)sizeof(double));
  for (ii = 0; ii < n; ii++) {
    X->data[X->size[0] * ii] = state->data[ii];
  }

  /* For rotational joint */
  cnr = 1.0;
  for (k = 0; k < (int)nH; k++) {
    n = incH->size[0];
    for (ii = 0; ii < n; ii++) {
      x_data[ii] = (incH->data[ii + incH->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg3 = false;
    while ((!exitg3) && (ii <= n)) {
      guard3 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg3 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (ii = 0; ii < n; ii++) {
      massnr_data[ii] = ii_data[ii];
    }

    /* Find entries in column */
    massnr_size[0] = n;
    for (ii = 0; ii < n; ii++) {
      b_massnr_data[ii] = (massnr_data[ii] == 1);
    }

    c_massnr_data.data = (boolean_T *)&b_massnr_data;
    c_massnr_data.size = (int *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    if (any(&c_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (ii = 0; ii < 3; ii++) {
        mx[ii] = X->data[(int)(anew + (-2.0 + (double)ii)) - 1];
      }

      for (ii = 0; ii < 2; ii++) {
        b_comPoints[ii] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * ii) - 1];
      }

      MGH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          mx, *(double (*)[2])&D->data[(int)cnr - 1]);
      cnr += 2.0;
    } else {
      anew = ((double)massnr_data[0] - 1.0) * 3.0;
      ndbl = ((double)massnr_data[1] - 1.0) * 3.0;
      for (ii = 0; ii < 3; ii++) {
        b_X[ii] = X->data[(int)(anew + (-2.0 + (double)ii)) - 1];
      }

      for (ii = 0; ii < 3; ii++) {
        b_X[ii + 3] = X->data[(int)(ndbl + (-2.0 + (double)ii)) - 1];
      }

      for (ii = 0; ii < 6; ii++) {
        b_mx[ii] = b_X[ii];
      }

      for (ii = 0; ii < 2; ii++) {
        b_comPoints[ii] = comPoints->data[((int)((double)massnr_data[0] - 1.0) +
          comPoints->size[0] * ii) - 1];
      }

      for (ii = 0; ii < 2; ii++) {
        c_comPoints[ii] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * ii) - 1];
      }

      MMH(*(double (*)[5])&DNA_Hpar->data[DNA_Hpar->size[0] * k], b_comPoints,
          c_comPoints, b_mx, *(double (*)[2])&D->data[(int)cnr - 1]);

      /* Constraints */
      cnr += 2.0;
    }
  }

  emxFree_real_T(&incH);

  /* For prismatic Joints */
  for (k = 0; k < (int)nP; k++) {
    n = incP->size[0];
    for (ii = 0; ii < n; ii++) {
      x_data[ii] = (incP->data[ii + incP->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= n)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (ii = 0; ii < n; ii++) {
      massnr_data[ii] = ii_data[ii];
    }

    /* Find entries in column */
    b_massnr_size[0] = n;
    for (ii = 0; ii < n; ii++) {
      d_massnr_data[ii] = (massnr_data[ii] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    if (any(&e_massnr_data)) {
      /* If this column contains ground */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (ii = 0; ii < 3; ii++) {
        mx[ii] = X->data[(int)(anew + (-2.0 + (double)ii)) - 1];
      }

      for (ii = 0; ii < 2; ii++) {
        b_comPoints[ii] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * ii) - 1];
      }

      D->data[(int)cnr - 1] = MGP(*(double (*)[2])&DNA_Ppar->data[DNA_Ppar->
        size[0] * k], DNA_Ppar->data[2 + DNA_Ppar->size[0] * k], b_comPoints, mx);
      cnr++;
    }
  }

  emxFree_real_T(&incP);

  /* For prismatic Joints */
  k = 0;
  emxInit_real_T(&cnrIdx, 2);
  emxInit_int32_T(&r6, 1);
  while (k <= (int)nPm - 1) {
    n = incPm->size[0];
    for (ii = 0; ii < n; ii++) {
      x_data[ii] = (incPm->data[ii + incPm->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= n)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= n) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (n == 1) {
      if (idx == 0) {
        n = 0;
      }
    } else if (1 > idx) {
      n = 0;
    } else {
      n = idx;
    }

    for (ii = 0; ii < n; ii++) {
      massnr_data[ii] = ii_data[ii];
    }

    /* Find entries in column */
    c_massnr_size[0] = n;
    for (ii = 0; ii < n; ii++) {
      f_massnr_data[ii] = (massnr_data[ii] == 1);
    }

    g_massnr_data.data = (boolean_T *)&f_massnr_data;
    g_massnr_data.size = (int *)&c_massnr_size;
    g_massnr_data.allocatedSize = 100;
    g_massnr_data.numDimensions = 1;
    g_massnr_data.canFreeData = false;
    if (any(&g_massnr_data)) {
      /* If this column contains ground */
      /*          keyboard  */
      anew = ((double)massnr_data[1] - 1.0) * 3.0;
      for (ii = 0; ii < 3; ii++) {
        mx[ii] = X->data[(int)(anew + (-2.0 + (double)ii)) - 1];
      }

      if (cnr + 1.0 < cnr) {
        n = 0;
        anew = cnr;
        apnd = cnr + 1.0;
      } else if (rtIsInf(cnr) || rtIsInf(cnr + 1.0)) {
        n = 1;
        anew = rtNaN;
        apnd = cnr + 1.0;
      } else {
        anew = cnr;
        ndbl = floor(((cnr + 1.0) - cnr) + 0.5);
        apnd = cnr + ndbl;
        cdiff = apnd - (cnr + 1.0);
        u1 = cnr + 1.0;
        if (anew >= u1) {
          u1 = anew;
        }

        if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
          ndbl++;
          apnd = cnr + 1.0;
        } else if (cdiff > 0.0) {
          apnd = cnr + (ndbl - 1.0);
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          n = (int)ndbl;
        } else {
          n = 0;
        }
      }

      ii = cnrIdx->size[0] * cnrIdx->size[1];
      cnrIdx->size[0] = 1;
      cnrIdx->size[1] = n;
      emxEnsureCapacity((emxArray__common *)cnrIdx, ii, (int)sizeof(double));
      if (n > 0) {
        cnrIdx->data[0] = anew;
        if (n > 1) {
          cnrIdx->data[n - 1] = apnd;
          idx = (n - 1) / 2;
          for (ii = 1; ii < idx; ii++) {
            cnrIdx->data[ii] = anew + (double)ii;
            cnrIdx->data[(n - ii) - 1] = apnd - (double)ii;
          }

          if (idx << 1 == n - 1) {
            cnrIdx->data[idx] = (anew + apnd) / 2.0;
          } else {
            cnrIdx->data[idx] = anew + (double)idx;
            cnrIdx->data[idx + 1] = apnd - (double)idx;
          }
        }
      }

      /*           keyboard  */
      ii = r6->size[0];
      r6->size[0] = cnrIdx->size[1];
      emxEnsureCapacity((emxArray__common *)r6, ii, (int)sizeof(int));
      n = cnrIdx->size[1];
      for (ii = 0; ii < n; ii++) {
        r6->data[ii] = (int)cnrIdx->data[cnrIdx->size[0] * ii] - 1;
      }

      for (ii = 0; ii < 2; ii++) {
        b_comPoints[ii] = comPoints->data[((int)((double)massnr_data[1] - 1.0) +
          comPoints->size[0] * ii) - 1];
      }

      MGPm(*(double (*)[2])&DNA_Pmpar->data[DNA_Pmpar->size[0] * k],
           DNA_Pmpar->data[2 + DNA_Pmpar->size[0] * k], DNA_Pmpar->data[3 +
           DNA_Pmpar->size[0] * k], DNA_Pmpar->data[4 + DNA_Pmpar->size[0] * k],
           b_comPoints, t, mx, c_comPoints);
      idx = r6->size[0];
      for (ii = 0; ii < idx; ii++) {
        D->data[r6->data[ii]] = c_comPoints[ii];
      }

      /*  keyboard  */
      cnr += 2.0;
    }

    k++;
  }

  emxFree_int32_T(&r6);
  emxFree_real_T(&cnrIdx);
  emxFree_real_T(&X);
  emxFree_real_T(&incPm);
  emxFree_real_T(&comPoints);
}

/*
 * File trailer for getDk.c
 *
 * [EOF]
 */
