/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeQdd.c
 *
 * Code generation for function 'computeQdd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "computeQdd.h"
#include "simulateDNA_emxutil.h"
#include "mldivide.h"
#include "eye.h"
#include "getForces.h"
#include "getDk.h"
#include "indexShapeCheck.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ag_emlrtRSI = { 9, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRSInfo bg_emlrtRSI = { 11, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRSInfo cg_emlrtRSI = { 15, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRSInfo dg_emlrtRSI = { 33, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRSInfo eg_emlrtRSI = { 34, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRSInfo fg_emlrtRSI = { 38, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRSInfo gg_emlrtRSI = { 39, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRSInfo hg_emlrtRSI = { 43, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRTEInfo qb_emlrtRTEI = { 6, 16, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRTEInfo rb_emlrtRTEI = { 15, 1, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRTEInfo sb_emlrtRTEI = { 23, 1, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtRTEInfo tb_emlrtRTEI = { 33, 1, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtDCInfo j_emlrtDCI = { 9, 6, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  1 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 9, 6, "state", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtECInfo o_emlrtECI = { -1, 13, 5, "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m"
};

static emlrtBCInfo we_emlrtBCI = { -1, -1, 17, 20, "DNA.Mpar", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 25, 24, "mass", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 26, 24, "mass", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 25, 9, "Mij", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 25, 15, "Mij", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 26, 9, "Mij", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 26, 15, "Mij", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 27, 24, "inertia", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 27, 9, "Mij", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 27, 13, "Mij", "computeQdd",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\computeQdd.m",
  0 };

/* Function Definitions */
void computeQdd(const emlrtStack *sp, real_T t, const emxArray_real_T *state,
                const emxArray_real_T *DNA_incstr, const emxArray_real_T
                *DNA_edgelabel, const emxArray_real_T *DNA_Mpar, const
                emxArray_real_T *DNA_Hpar, const emxArray_real_T *DNA_Spar,
                const emxArray_real_T *DNA_Ppar, const emxArray_real_T
                *DNA_Pmpar, emxArray_real_T *qdd)
{
  real_T nX;
  int32_T i30;
  int32_T i31;
  emxArray_real_T *F;
  emxArray_real_T *Mass;
  emxArray_real_T *Dqq;
  emxArray_real_T *Dt;
  int32_T i32;
  emxArray_real_T *Dqt;
  emxArray_real_T *Dtt;
  int32_T iv60[2];
  int32_T loop_ub;
  int32_T i33;
  int32_T result;
  emxArray_real_T *Mij;
  int32_T nM;
  real_T d1;
  int32_T k;
  emxArray_real_T *varargin_2;
  int32_T b_result;
  int32_T c_result;
  int32_T d_result;
  boolean_T empty_non_axis_sizes;
  emxArray_real_T *varargin_1;
  cell_wrap_0 reshapes[2];
  cell_wrap_0 b_reshapes[2];
  emxArray_real_T *b_Mij;
  emxArray_real_T *b_state;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  nX = (real_T)state->size[0] / 2.0;

  /* Get the number of coordinates */
  if (nX + 1.0 > state->size[0]) {
    i30 = 1;
    i31 = 1;
  } else {
    if (nX + 1.0 != muDoubleScalarFloor(nX + 1.0)) {
      emlrtIntegerCheckR2012b(nX + 1.0, &j_emlrtDCI, sp);
    }

    i31 = state->size[0];
    i30 = (int32_T)(nX + 1.0);
    if (!((i30 >= 1) && (i30 <= i31))) {
      emlrtDynamicBoundsCheckR2012b(i30, 1, i31, &ve_emlrtBCI, sp);
    }

    i31 = state->size[0];
    i32 = state->size[0];
    if (!((i32 >= 1) && (i32 <= i31))) {
      emlrtDynamicBoundsCheckR2012b(i32, 1, i31, &ve_emlrtBCI, sp);
    }

    i31 = i32 + 1;
  }

  emxInit_real_T1(sp, &F, 1, &rb_emlrtRTEI, true);
  emxInit_real_T(sp, &Mass, 2, &tb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Dqq, 1, &qb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Dt, 1, &qb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Dqt, 1, &qb_emlrtRTEI, true);
  emxInit_real_T1(sp, &Dtt, 1, &qb_emlrtRTEI, true);
  iv60[0] = 1;
  iv60[1] = i31 - i30;
  st.site = &ag_emlrtRSI;
  indexShapeCheck(&st, state->size[0], iv60);

  /* Get the velocity vector */
  st.site = &bg_emlrtRSI;
  d_getDk(&st, t, state, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar,
          DNA_Ppar, DNA_Pmpar, F, Mass, Dqq, Dt, Dqt, Dtt);

  /* Get Jacobian and convective accelerations */
  i32 = Dqt->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Dqt, i32, (int32_T)sizeof(real_T),
                    &qb_emlrtRTEI);
  loop_ub = Dqt->size[0];
  for (i32 = 0; i32 < loop_ub; i32++) {
    Dqt->data[i32] *= 2.0;
  }

  i32 = Dqt->size[0];
  i33 = Dqq->size[0];
  if (i32 != i33) {
    emlrtSizeEqCheck1DR2012b(i32, i33, &o_emlrtECI, sp);
  }

  i32 = Dqt->size[0];
  i33 = Dtt->size[0];
  if (i32 != i33) {
    emlrtSizeEqCheck1DR2012b(i32, i33, &o_emlrtECI, sp);
  }

  st.site = &cg_emlrtRSI;
  getForces(&st, t, state, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar,
            DNA_Spar, DNA_Ppar, DNA_Pmpar, F);
  if (2 > DNA_Mpar->size[0]) {
    i32 = 1;
    i33 = 1;
  } else {
    i32 = 2;
    i33 = DNA_Mpar->size[0];
    result = DNA_Mpar->size[0];
    if (!((result >= 1) && (result <= i33))) {
      emlrtDynamicBoundsCheckR2012b(result, 1, i33, &we_emlrtBCI, sp);
    }

    i33 = result + 1;
  }

  result = Dt->size[0];
  Dt->size[0] = i33 - i32;
  emxEnsureCapacity(sp, (emxArray__common *)Dt, result, (int32_T)sizeof(real_T),
                    &qb_emlrtRTEI);
  loop_ub = i33 - i32;
  for (result = 0; result < loop_ub; result++) {
    Dt->data[result] = 0.083333333333333329 * DNA_Mpar->data[((i32 + result) +
      (DNA_Mpar->size[0] << 1)) - 1];
  }

  emxInit_real_T(sp, &Mij, 2, &sb_emlrtRTEI, true);
  nM = (i33 - i32) - 1;
  d1 = (real_T)(i33 - i32) * 3.0;
  result = Mij->size[0] * Mij->size[1];
  Mij->size[0] = (int32_T)d1;
  Mij->size[1] = (int32_T)d1;
  emxEnsureCapacity(sp, (emxArray__common *)Mij, result, (int32_T)sizeof(real_T),
                    &qb_emlrtRTEI);
  loop_ub = (int32_T)d1 * (int32_T)d1;
  for (result = 0; result < loop_ub; result++) {
    Mij->data[result] = 0.0;
  }

  /* Build mass matrix */
  k = 0;
  while (k <= nM) {
    result = i33 - i32;
    b_result = 1 + k;
    if (!((b_result >= 1) && (b_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(b_result, 1, result, &xe_emlrtBCI, sp);
    }

    result = Mij->size[0];
    b_result = (int32_T)((1.0 + (real_T)k) * 3.0 - 2.0);
    if (!((b_result >= 1) && (b_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(b_result, 1, result, &af_emlrtBCI, sp);
    }

    result = Mij->size[1];
    d_result = (int32_T)((1.0 + (real_T)k) * 3.0 - 2.0);
    if (!((d_result >= 1) && (d_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(d_result, 1, result, &bf_emlrtBCI, sp);
    }

    Mij->data[(b_result + Mij->size[0] * (d_result - 1)) - 1] = DNA_Mpar->data
      [((i32 + k) + (DNA_Mpar->size[0] << 1)) - 1];
    result = i33 - i32;
    b_result = 1 + k;
    if (!((b_result >= 1) && (b_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(b_result, 1, result, &ye_emlrtBCI, sp);
    }

    result = Mij->size[0];
    b_result = (int32_T)((1.0 + (real_T)k) * 3.0 - 1.0);
    if (!((b_result >= 1) && (b_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(b_result, 1, result, &cf_emlrtBCI, sp);
    }

    result = Mij->size[1];
    d_result = (int32_T)((1.0 + (real_T)k) * 3.0 - 1.0);
    if (!((d_result >= 1) && (d_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(d_result, 1, result, &df_emlrtBCI, sp);
    }

    Mij->data[(b_result + Mij->size[0] * (d_result - 1)) - 1] = DNA_Mpar->data
      [((i32 + k) + (DNA_Mpar->size[0] << 1)) - 1];
    result = Dt->size[0];
    b_result = 1 + k;
    if (!((b_result >= 1) && (b_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(b_result, 1, result, &ef_emlrtBCI, sp);
    }

    result = Mij->size[0];
    d_result = (int32_T)((1.0 + (real_T)k) * 3.0);
    if (!((d_result >= 1) && (d_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(d_result, 1, result, &ff_emlrtBCI, sp);
    }

    result = Mij->size[1];
    c_result = (int32_T)((1.0 + (real_T)k) * 3.0);
    if (!((c_result >= 1) && (c_result <= result))) {
      emlrtDynamicBoundsCheckR2012b(c_result, 1, result, &gf_emlrtBCI, sp);
    }

    Mij->data[(d_result + Mij->size[0] * (c_result - 1)) - 1] = Dt->
      data[b_result - 1];
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&Dt);
  emxInit_real_T(sp, &varargin_2, 2, &qb_emlrtRTEI, true);
  c_result = Mass->size[0];
  st.site = &dg_emlrtRSI;
  i32 = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = Mass->size[1];
  varargin_2->size[1] = Mass->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i32, (int32_T)sizeof
                    (real_T), &qb_emlrtRTEI);
  loop_ub = Mass->size[0];
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_result = Mass->size[1];
    for (i33 = 0; i33 < b_result; i33++) {
      varargin_2->data[i33 + varargin_2->size[0] * i32] = Mass->data[i32 +
        Mass->size[0] * i33];
    }
  }

  b_st.site = &jb_emlrtRSI;
  if (!((Mij->size[0] == 0) || (Mij->size[1] == 0))) {
    d_result = Mij->size[0];
  } else if (!((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0))) {
    d_result = varargin_2->size[0];
  } else {
    d_result = muIntScalarMax_sint32(Mij->size[0], 0);
    if (varargin_2->size[0] > d_result) {
      d_result = varargin_2->size[0];
    }
  }

  c_st.site = &kb_emlrtRSI;
  if ((d_result == Mij->size[0]) || ((Mij->size[0] == 0) || (Mij->size[1] == 0)))
  {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((d_result == varargin_2->size[0]) || ((varargin_2->size[0] == 0) ||
       (varargin_2->size[1] == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || (!((Mij->size[0] == 0) || (Mij->size[1] == 0)))) {
    result = Mij->size[1];
  } else {
    result = 0;
  }

  if (empty_non_axis_sizes || (!((varargin_2->size[0] == 0) || (varargin_2->
         size[1] == 0)))) {
    b_result = varargin_2->size[1];
  } else {
    b_result = 0;
  }

  emxInit_real_T(&b_st, &varargin_1, 2, &qb_emlrtRTEI, true);
  i32 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = d_result;
  varargin_1->size[1] = result + b_result;
  emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, i32, (int32_T)sizeof
                    (real_T), &qb_emlrtRTEI);
  for (i32 = 0; i32 < result; i32++) {
    for (i33 = 0; i33 < d_result; i33++) {
      varargin_1->data[i33 + varargin_1->size[0] * i32] = Mij->data[i33 +
        d_result * i32];
    }
  }

  for (i32 = 0; i32 < b_result; i32++) {
    for (i33 = 0; i33 < d_result; i33++) {
      varargin_1->data[i33 + varargin_1->size[0] * (i32 + result)] =
        varargin_2->data[i33 + d_result * i32];
    }
  }

  st.site = &eg_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  if (!((Mass->size[0] == 0) || (Mass->size[1] == 0))) {
    d_result = Mass->size[0];
  } else if (!(c_result == 0)) {
    d_result = c_result;
  } else {
    d_result = muIntScalarMax_sint32(Mass->size[0], 0);
    if (0 > d_result) {
      d_result = 0;
    }
  }

  c_st.site = &kb_emlrtRSI;
  if ((d_result == Mass->size[0]) || ((Mass->size[0] == 0) || (Mass->size[1] ==
        0))) {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((d_result == c_result) || (c_result == 0)) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || (!((Mass->size[0] == 0) || (Mass->size[1] == 0))))
  {
    result = Mass->size[1];
  } else {
    result = 0;
  }

  if (empty_non_axis_sizes || (!(c_result == 0))) {
  } else {
    c_result = 0;
  }

  emxInitMatrix_cell_wrap_01(&b_st, reshapes, &p_emlrtRTEI, true);
  i32 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
  reshapes[1].f1->size[0] = d_result;
  reshapes[1].f1->size[1] = c_result;
  emxEnsureCapacity(&b_st, (emxArray__common *)reshapes[1].f1, i32, (int32_T)
                    sizeof(real_T), &qb_emlrtRTEI);
  loop_ub = d_result * c_result;
  for (i32 = 0; i32 < loop_ub; i32++) {
    reshapes[1].f1->data[i32] = 0.0;
  }

  i32 = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = d_result;
  varargin_2->size[1] = result + reshapes[1].f1->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)varargin_2, i32, (int32_T)sizeof
                    (real_T), &qb_emlrtRTEI);
  for (i32 = 0; i32 < result; i32++) {
    for (i33 = 0; i33 < d_result; i33++) {
      varargin_2->data[i33 + varargin_2->size[0] * i32] = Mass->data[i33 +
        d_result * i32];
    }
  }

  loop_ub = reshapes[1].f1->size[1];
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_result = reshapes[1].f1->size[0];
    for (i33 = 0; i33 < b_result; i33++) {
      varargin_2->data[i33 + varargin_2->size[0] * (i32 + result)] = reshapes[1]
        .f1->data[i33 + reshapes[1].f1->size[0] * i32];
    }
  }

  emxFreeMatrix_cell_wrap_01(reshapes);
  st.site = &dg_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  if (!((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0))) {
    d_result = varargin_1->size[1];
  } else if (!((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0))) {
    d_result = varargin_2->size[1];
  } else {
    d_result = muIntScalarMax_sint32(varargin_1->size[1], 0);
    if (varargin_2->size[1] > d_result) {
      d_result = varargin_2->size[1];
    }
  }

  c_st.site = &kb_emlrtRSI;
  if ((d_result == varargin_1->size[1]) || ((varargin_1->size[0] == 0) ||
       (varargin_1->size[1] == 0))) {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((d_result == varargin_2->size[1]) || ((varargin_2->size[0] == 0) ||
       (varargin_2->size[1] == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || (!((varargin_1->size[0] == 0) || (varargin_1->
         size[1] == 0)))) {
    result = varargin_1->size[0];
  } else {
    result = 0;
  }

  if (empty_non_axis_sizes || (!((varargin_2->size[0] == 0) || (varargin_2->
         size[1] == 0)))) {
    b_result = varargin_2->size[0];
  } else {
    b_result = 0;
  }

  i32 = Mass->size[0] * Mass->size[1];
  Mass->size[0] = result + b_result;
  Mass->size[1] = d_result;
  emxEnsureCapacity(&b_st, (emxArray__common *)Mass, i32, (int32_T)sizeof(real_T),
                    &qb_emlrtRTEI);
  for (i32 = 0; i32 < d_result; i32++) {
    for (i33 = 0; i33 < result; i33++) {
      Mass->data[i33 + Mass->size[0] * i32] = varargin_1->data[i33 + result *
        i32];
    }
  }

  for (i32 = 0; i32 < d_result; i32++) {
    for (i33 = 0; i33 < b_result; i33++) {
      Mass->data[(i33 + result) + Mass->size[0] * i32] = varargin_2->data[i33 +
        b_result * i32];
    }
  }

  st.site = &fg_emlrtRSI;
  eye(&st, i31 - i30, varargin_1);
  if ((Mass->size[0] == 0) || (Mass->size[1] == 0)) {
    c_result = 0;
  } else {
    c_result = muIntScalarMax_sint32(Mass->size[0], Mass->size[1]);
  }

  st.site = &fg_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  if (!((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0))) {
    d_result = varargin_1->size[0];
  } else if (!((i31 - i30 == 0) || (c_result == 0))) {
    d_result = i31 - i30;
  } else {
    d_result = muIntScalarMax_sint32(varargin_1->size[0], 0);
    if (i31 - i30 > d_result) {
      d_result = i31 - i30;
    }
  }

  c_st.site = &kb_emlrtRSI;
  if ((d_result == varargin_1->size[0]) || ((varargin_1->size[0] == 0) ||
       (varargin_1->size[1] == 0))) {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((d_result == i31 - i30) || ((i31 - i30 == 0) || (c_result == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || (!((varargin_1->size[0] == 0) || (varargin_1->
         size[1] == 0)))) {
    result = varargin_1->size[1];
  } else {
    result = 0;
  }

  if (empty_non_axis_sizes || (!((i31 - i30 == 0) || (c_result == 0)))) {
  } else {
    c_result = 0;
  }

  emxInitMatrix_cell_wrap_01(&b_st, b_reshapes, &p_emlrtRTEI, true);
  i32 = b_reshapes[1].f1->size[0] * b_reshapes[1].f1->size[1];
  b_reshapes[1].f1->size[0] = d_result;
  b_reshapes[1].f1->size[1] = c_result;
  emxEnsureCapacity(&b_st, (emxArray__common *)b_reshapes[1].f1, i32, (int32_T)
                    sizeof(real_T), &qb_emlrtRTEI);
  loop_ub = d_result * c_result;
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_reshapes[1].f1->data[i32] = 0.0;
  }

  i32 = Mij->size[0] * Mij->size[1];
  Mij->size[0] = d_result;
  Mij->size[1] = result + b_reshapes[1].f1->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)Mij, i32, (int32_T)sizeof(real_T),
                    &qb_emlrtRTEI);
  for (i32 = 0; i32 < result; i32++) {
    for (i33 = 0; i33 < d_result; i33++) {
      Mij->data[i33 + Mij->size[0] * i32] = varargin_1->data[i33 + d_result *
        i32];
    }
  }

  loop_ub = b_reshapes[1].f1->size[1];
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_result = b_reshapes[1].f1->size[0];
    for (i33 = 0; i33 < b_result; i33++) {
      Mij->data[i33 + Mij->size[0] * (i32 + result)] = b_reshapes[1].f1->
        data[i33 + b_reshapes[1].f1->size[0] * i32];
    }
  }

  emxFreeMatrix_cell_wrap_01(b_reshapes);
  b_result = i31 - i30;
  if ((Mass->size[0] == 0) || (Mass->size[1] == 0)) {
    c_result = 0;
  } else {
    c_result = muIntScalarMax_sint32(Mass->size[0], Mass->size[1]);
  }

  st.site = &gg_emlrtRSI;
  i32 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = c_result;
  varargin_1->size[1] = b_result;
  emxEnsureCapacity(&st, (emxArray__common *)varargin_1, i32, (int32_T)sizeof
                    (real_T), &qb_emlrtRTEI);
  for (i32 = 0; i32 < b_result; i32++) {
    for (i33 = 0; i33 < c_result; i33++) {
      varargin_1->data[i33 + varargin_1->size[0] * i32] = 0.0;
    }
  }

  b_st.site = &jb_emlrtRSI;
  if (!((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0))) {
    d_result = varargin_1->size[0];
  } else if (!((Mass->size[0] == 0) || (Mass->size[1] == 0))) {
    d_result = Mass->size[0];
  } else {
    d_result = muIntScalarMax_sint32(varargin_1->size[0], 0);
    if (Mass->size[0] > d_result) {
      d_result = Mass->size[0];
    }
  }

  c_st.site = &kb_emlrtRSI;
  if ((d_result == varargin_1->size[0]) || ((varargin_1->size[0] == 0) ||
       (varargin_1->size[1] == 0))) {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((d_result == Mass->size[0]) || ((Mass->size[0] == 0) || (Mass->size[1] ==
        0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || (!((varargin_1->size[0] == 0) || (varargin_1->
         size[1] == 0)))) {
    result = varargin_1->size[1];
  } else {
    result = 0;
  }

  if (empty_non_axis_sizes || (!((Mass->size[0] == 0) || (Mass->size[1] == 0))))
  {
    b_result = Mass->size[1];
  } else {
    b_result = 0;
  }

  i32 = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = d_result;
  varargin_2->size[1] = result + b_result;
  emxEnsureCapacity(&b_st, (emxArray__common *)varargin_2, i32, (int32_T)sizeof
                    (real_T), &qb_emlrtRTEI);
  for (i32 = 0; i32 < result; i32++) {
    for (i33 = 0; i33 < d_result; i33++) {
      varargin_2->data[i33 + varargin_2->size[0] * i32] = varargin_1->data[i33 +
        d_result * i32];
    }
  }

  emxFree_real_T(&varargin_1);
  for (i32 = 0; i32 < b_result; i32++) {
    for (i33 = 0; i33 < d_result; i33++) {
      varargin_2->data[i33 + varargin_2->size[0] * (i32 + result)] = Mass->
        data[i33 + d_result * i32];
    }
  }

  emxFree_real_T(&Mass);
  st.site = &fg_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  if (!((Mij->size[0] == 0) || (Mij->size[1] == 0))) {
    d_result = Mij->size[1];
  } else if (!((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0))) {
    d_result = varargin_2->size[1];
  } else {
    d_result = muIntScalarMax_sint32(Mij->size[1], 0);
    if (varargin_2->size[1] > d_result) {
      d_result = varargin_2->size[1];
    }
  }

  c_st.site = &kb_emlrtRSI;
  if ((d_result == Mij->size[1]) || ((Mij->size[0] == 0) || (Mij->size[1] == 0)))
  {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((d_result == varargin_2->size[1]) || ((varargin_2->size[0] == 0) ||
       (varargin_2->size[1] == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (empty_non_axis_sizes) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &nc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || (!((Mij->size[0] == 0) || (Mij->size[1] == 0)))) {
    result = Mij->size[0];
  } else {
    result = 0;
  }

  if (empty_non_axis_sizes || (!((varargin_2->size[0] == 0) || (varargin_2->
         size[1] == 0)))) {
    b_result = varargin_2->size[0];
  } else {
    b_result = 0;
  }

  emxInit_real_T(&b_st, &b_Mij, 2, &qb_emlrtRTEI, true);
  i32 = b_Mij->size[0] * b_Mij->size[1];
  b_Mij->size[0] = result + b_result;
  b_Mij->size[1] = d_result;
  emxEnsureCapacity(sp, (emxArray__common *)b_Mij, i32, (int32_T)sizeof(real_T),
                    &qb_emlrtRTEI);
  for (i32 = 0; i32 < d_result; i32++) {
    for (i33 = 0; i33 < result; i33++) {
      b_Mij->data[i33 + b_Mij->size[0] * i32] = Mij->data[i33 + result * i32];
    }
  }

  emxFree_real_T(&Mij);
  for (i32 = 0; i32 < d_result; i32++) {
    for (i33 = 0; i33 < b_result; i33++) {
      b_Mij->data[(i33 + result) + b_Mij->size[0] * i32] = varargin_2->data[i33
        + b_result * i32];
    }
  }

  emxFree_real_T(&varargin_2);
  emxInit_real_T1(sp, &b_state, 1, &qb_emlrtRTEI, true);
  i32 = b_state->size[0];
  b_state->size[0] = ((i31 - i30) + F->size[0]) + Dqt->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_state, i32, (int32_T)sizeof(real_T),
                    &qb_emlrtRTEI);
  loop_ub = i31 - i30;
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_state->data[i32] = state->data[(i30 + i32) - 1];
  }

  loop_ub = F->size[0];
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_state->data[(i32 + i31) - i30] = F->data[i32];
  }

  loop_ub = Dqt->size[0];
  for (i32 = 0; i32 < loop_ub; i32++) {
    b_state->data[((i32 + i31) - i30) + F->size[0]] = -((Dqt->data[i32] +
      Dqq->data[i32]) + Dtt->data[i32]);
  }

  emxFree_real_T(&Dtt);
  emxFree_real_T(&Dqt);
  emxFree_real_T(&Dqq);
  emxFree_real_T(&F);
  st.site = &hg_emlrtRSI;
  mldivide(&st, b_Mij, b_state, qdd);
  emxFree_real_T(&b_state);
  emxFree_real_T(&b_Mij);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (computeQdd.c) */
