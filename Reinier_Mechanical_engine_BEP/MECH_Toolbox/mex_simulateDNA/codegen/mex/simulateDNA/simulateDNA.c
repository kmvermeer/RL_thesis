/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * simulateDNA.c
 *
 * Code generation for function 'simulateDNA'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "simulateDNA_emxutil.h"
#include "rk4.h"
#include "getCompoints.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9, "simulateDNA",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\mex_simulateDNA\\simulateDNA.m"
};

static emlrtRSInfo b_emlrtRSI = { 12, "simulateDNA",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\mex_simulateDNA\\simulateDNA.m"
};

static emlrtRSInfo c_emlrtRSI = { 7, "getInitialconditions",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getInitialconditions.m"
};

static emlrtRTEInfo emlrtRTEI = { 7, 25, "simulateDNA",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\mex_simulateDNA\\simulateDNA.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 9, 1, "simulateDNA",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\mex_simulateDNA\\simulateDNA.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 7, 1, "getInitialconditions",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getInitialconditions.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 13, 27, "comPoints",
  "getInitialconditions",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getInitialconditions.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 13, 5, "x0", "getInitialconditions",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getInitialconditions.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 14, 27, "comPoints",
  "getInitialconditions",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getInitialconditions.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 14, 5, "x0", "getInitialconditions",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\getInitialconditions.m",
  0 };

/* Function Definitions */
void simulateDNA(const emlrtStack *sp, const struct0_T *DNA, real_T T, real_T h,
                 emxArray_real_T *t, emxArray_real_T *qss, real_T *flag)
{
  emxArray_real_T *x0;
  emxArray_real_T *comPoints;
  int32_T i0;
  int32_T i1;
  int32_T loop_ub;
  int32_T k;
  emxArray_real_T *r0;
  int32_T xs;
  int32_T cs;
  real_T dv0[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &x0, 2, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &comPoints, 2, &c_emlrtRTEI, true);

  /* simulateDNA - computes the states of the mechanism represented by DNA. The */
  /* mex-version of this function is used in the EA. When compiling the */
  /* functions getCompoints.m and getDk.m should be checked not to contain */
  /* getInc_mex. */
  st.site = &emlrtRSI;
  b_st.site = &c_emlrtRSI;
  getCompoints(&b_st, DNA->incstr, DNA->edgelabel, DNA->Mpar, DNA->Hpar,
               DNA->Spar, DNA->Ppar, DNA->Pmpar, comPoints);

  /* body boundaries and com */
  i0 = comPoints->size[0];
  i1 = comPoints->size[0];
  loop_ub = x0->size[0] * x0->size[1];
  x0->size[0] = 1;
  x0->size[1] = (int32_T)(3.0 * (real_T)i1);
  emxEnsureCapacity(&st, (emxArray__common *)x0, loop_ub, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = (int32_T)(3.0 * (real_T)i1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    x0->data[i1] = 0.0;
  }

  k = 0;
  while (k <= i0 - 1) {
    i1 = comPoints->size[0];
    loop_ub = 1 + k;
    if (!((loop_ub >= 1) && (loop_ub <= i1))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &emlrtBCI, &st);
    }

    i1 = x0->size[1];
    xs = (int32_T)((1.0 + (real_T)k) * 3.0 - 2.0);
    if (!((xs >= 1) && (xs <= i1))) {
      emlrtDynamicBoundsCheckR2012b(xs, 1, i1, &b_emlrtBCI, &st);
    }

    x0->data[xs - 1] = comPoints->data[loop_ub - 1];
    i1 = comPoints->size[0];
    loop_ub = 1 + k;
    if (!((loop_ub >= 1) && (loop_ub <= i1))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &c_emlrtBCI, &st);
    }

    i1 = x0->size[1];
    xs = (int32_T)((1.0 + (real_T)k) * 3.0 - 1.0);
    if (!((xs >= 1) && (xs <= i1))) {
      emlrtDynamicBoundsCheckR2012b(xs, 1, i1, &d_emlrtBCI, &st);
    }

    x0->data[xs - 1] = comPoints->data[(loop_ub + comPoints->size[0]) - 1];
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emxFree_real_T(&comPoints);
  emxInit_real_T(&st, &r0, 2, &emlrtRTEI, true);
  xs = x0->size[1];
  cs = (int32_T)(3.0 * (real_T)i0);
  i1 = x0->size[0] * x0->size[1];
  x0->size[1] = xs + (int32_T)(3.0 * (real_T)i0);
  emxEnsureCapacity(&st, (emxArray__common *)x0, i1, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = (int32_T)(3.0 * (real_T)i0);
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    r0->data[r0->size[0] * i0] = 0.0;
  }

  for (i0 = 0; i0 < cs; i0++) {
    x0->data[xs + i0] = r0->data[i0];
  }

  emxFree_real_T(&r0);
  dv0[0] = 0.0;
  dv0[1] = T;
  st.site = &b_emlrtRSI;
  rk4(&st, dv0, x0, h, (real_T)x0->size[1] / 2.0, DNA->incstr, DNA->edgelabel,
      DNA->Mpar, DNA->Hpar, DNA->Spar, DNA->Ppar, DNA->Pmpar, t, qss, flag);
  emxFree_real_T(&x0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (simulateDNA.c) */
