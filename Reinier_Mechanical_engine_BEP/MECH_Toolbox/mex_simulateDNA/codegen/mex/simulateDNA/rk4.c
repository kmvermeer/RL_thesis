/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rk4.c
 *
 * Code generation for function 'rk4'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "rk4.h"
#include "simulateDNA_emxutil.h"
#include "isequal.h"
#include "any.h"
#include "eom.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo wb_emlrtRSI = { 19, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRSInfo xb_emlrtRSI = { 30, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRSInfo yb_emlrtRSI = { 31, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRSInfo ac_emlrtRSI = { 32, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRSInfo bc_emlrtRSI = { 33, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRSInfo cc_emlrtRSI = { 47, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 11, 31, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRTEInfo s_emlrtRTEI = { 30, 5, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRTEInfo t_emlrtRTEI = { 31, 5, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRTEInfo u_emlrtRTEI = { 32, 5, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 33, 5, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRTEInfo w_emlrtRTEI = { 34, 5, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtRTEInfo x_emlrtRTEI = { 44, 5, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 47, 33, "dyout", "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 47, 33, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m",
  1 };

static emlrtECInfo c_emlrtECI = { 2, 44, 13, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 44, 28, "yout", "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m",
  0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 44, 18, "yout", "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m",
  0 };

static emlrtECInfo d_emlrtECI = { -1, 42, 5, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 42, 10, "yout", "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m",
  0 };

static emlrtECInfo e_emlrtECI = { -1, 24, 1, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 24, 6, "yout", "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m",
  0 };

static emlrtECInfo f_emlrtECI = { -1, 34, 12, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtECInfo g_emlrtECI = { -1, 34, 22, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtECInfo h_emlrtECI = { -1, 33, 16, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtECInfo i_emlrtECI = { -1, 32, 20, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtECInfo j_emlrtECI = { -1, 31, 20, "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m"
};

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 41, 5, "tout", "rk4",
  "C:\\Users\\Reinier\\Box Sync\\Reinier PhD\\3_Matlab\\Mechanical_engine\\rk4.m",
  0 };

/* Function Definitions */
void rk4(const emlrtStack *sp, const real_T tspan[2], const emxArray_real_T
         *b_y0, real_T h, real_T nx0, const emxArray_real_T *DNA_incstr, const
         emxArray_real_T *DNA_edgelabel, const emxArray_real_T *DNA_Mpar, const
         emxArray_real_T *DNA_Hpar, const emxArray_real_T *DNA_Spar, const
         emxArray_real_T *DNA_Ppar, const emxArray_real_T *DNA_Pmpar,
         emxArray_real_T *tout, emxArray_real_T *yout, real_T *flag)
{
  emxArray_real_T *ynew;
  real_T t;
  int32_T i8;
  int32_T nm1d2;
  int32_T n;
  real_T anew;
  real_T apnd;
  boolean_T n_too_large;
  real_T ndbl;
  real_T cdiff;
  emxArray_real_T *r3;
  int32_T k;
  emxArray_int32_T *r4;
  emxArray_real_T *c_y0;
  int32_T iv6[2];
  emxArray_real_T *d_y0;
  int32_T e_y0[1];
  emxArray_real_T *s1;
  emxArray_real_T *s2;
  emxArray_real_T *s3;
  emxArray_real_T *s4;
  emxArray_real_T *dyout;
  emxArray_boolean_T *x;
  emxArray_boolean_T *r5;
  emxArray_real_T *b_ynew;
  emxArray_real_T *c_ynew;
  emxArray_real_T *d_ynew;
  emxArray_real_T *e_ynew;
  emxArray_real_T *b_yout;
  emxArray_real_T *c_yout;
  boolean_T guard1 = false;
  int32_T exitg1;
  real_T tnew;
  int32_T iv7[2];
  int32_T iv8[2];
  int32_T d_yout[2];
  int32_T e_yout[2];
  boolean_T y;
  boolean_T exitg2;
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
  emxInit_real_T1(sp, &ynew, 1, &w_emlrtRTEI, true);

  /*   Reinier Kuppens 4252071 20-03-2014 */
  /*    */
  /*   Runge Kutta 4th order */
  *flag = 1.0;
  t = 0.0;
  i8 = ynew->size[0];
  ynew->size[0] = b_y0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)ynew, i8, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  nm1d2 = b_y0->size[1];
  for (i8 = 0; i8 < nm1d2; i8++) {
    ynew->data[i8] = b_y0->data[i8];
  }

  st.site = &wb_emlrtRSI;
  b_st.site = &dc_emlrtRSI;
  if (muDoubleScalarIsNaN(h) || muDoubleScalarIsNaN(tspan[1])) {
    n = 1;
    anew = rtNaN;
    apnd = tspan[1];
    n_too_large = false;
  } else if ((h == 0.0) || ((0.0 < tspan[1]) && (h < 0.0)) || ((tspan[1] < 0.0) &&
              (h > 0.0))) {
    n = 0;
    anew = 0.0;
    apnd = tspan[1];
    n_too_large = false;
  } else if (muDoubleScalarIsInf(tspan[1])) {
    n = 1;
    anew = rtNaN;
    apnd = tspan[1];
    if (muDoubleScalarIsInf(h) || (0.0 == tspan[1])) {
      n_too_large = true;
    } else {
      n_too_large = false;
    }

    n_too_large = !n_too_large;
  } else if (muDoubleScalarIsInf(h)) {
    n = 1;
    anew = 0.0;
    apnd = tspan[1];
    n_too_large = false;
  } else {
    anew = 0.0;
    ndbl = muDoubleScalarFloor(tspan[1] / h + 0.5);
    apnd = ndbl * h;
    if (h > 0.0) {
      cdiff = apnd - tspan[1];
    } else {
      cdiff = tspan[1] - apnd;
    }

    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarAbs
        (tspan[1])) {
      ndbl++;
      apnd = tspan[1];
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * h;
    } else {
      ndbl++;
    }

    n_too_large = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }
  }

  c_st.site = &ec_emlrtRSI;
  if (!n_too_large) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &ad_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      0);
  }

  emxInit_real_T(&c_st, &r3, 2, &r_emlrtRTEI, true);
  i8 = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = n;
  emxEnsureCapacity(&b_st, (emxArray__common *)r3, i8, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  if (n > 0) {
    r3->data[0] = anew;
    if (n > 1) {
      r3->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      c_st.site = &fc_emlrtRSI;
      for (k = 1; k < nm1d2; k++) {
        ndbl = (real_T)k * h;
        r3->data[k] = anew + ndbl;
        r3->data[(n - k) - 1] = apnd - ndbl;
      }

      if (nm1d2 << 1 == n - 1) {
        r3->data[nm1d2] = (anew + apnd) / 2.0;
      } else {
        ndbl = (real_T)nm1d2 * h;
        r3->data[nm1d2] = anew + ndbl;
        r3->data[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }

  i8 = tout->size[0];
  tout->size[0] = r3->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)tout, i8, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  nm1d2 = r3->size[1];
  for (i8 = 0; i8 < nm1d2; i8++) {
    tout->data[i8] = 0.0;
  }

  i8 = yout->size[0] * yout->size[1];
  yout->size[0] = r3->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)yout, i8, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  nm1d2 = b_y0->size[1];
  i8 = yout->size[0] * yout->size[1];
  yout->size[1] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)yout, i8, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  nm1d2 = b_y0->size[1];
  nm1d2 *= r3->size[1];
  for (i8 = 0; i8 < nm1d2; i8++) {
    yout->data[i8] = 0.0;
  }

  emxInit_int32_T1(sp, &r4, 1, &r_emlrtRTEI, true);
  nm1d2 = r3->size[1];
  if (!(1 <= nm1d2)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, nm1d2, &nc_emlrtBCI, sp);
  }

  nm1d2 = b_y0->size[1];
  i8 = r4->size[0];
  r4->size[0] = nm1d2;
  emxEnsureCapacity(sp, (emxArray__common *)r4, i8, (int32_T)sizeof(int32_T),
                    &r_emlrtRTEI);
  for (i8 = 0; i8 < nm1d2; i8++) {
    r4->data[i8] = i8;
  }

  emxInit_real_T1(sp, &c_y0, 1, &r_emlrtRTEI, true);
  iv6[0] = 1;
  iv6[1] = r4->size[0];
  i8 = c_y0->size[0];
  c_y0->size[0] = b_y0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_y0, i8, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  nm1d2 = b_y0->size[1];
  for (i8 = 0; i8 < nm1d2; i8++) {
    c_y0->data[i8] = b_y0->data[b_y0->size[0] * i8];
  }

  emxInit_real_T1(sp, &d_y0, 1, &r_emlrtRTEI, true);
  e_y0[0] = c_y0->size[0];
  emlrtSubAssignSizeCheckR2012b(iv6, 2, e_y0, 1, &e_emlrtECI, sp);
  i8 = d_y0->size[0];
  d_y0->size[0] = b_y0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)d_y0, i8, (int32_T)sizeof(real_T),
                    &r_emlrtRTEI);
  nm1d2 = b_y0->size[1];
  emxFree_real_T(&c_y0);
  for (i8 = 0; i8 < nm1d2; i8++) {
    d_y0->data[i8] = b_y0->data[b_y0->size[0] * i8];
  }

  nm1d2 = r4->size[0];
  for (i8 = 0; i8 < nm1d2; i8++) {
    yout->data[yout->size[0] * r4->data[i8]] = d_y0->data[i8];
  }

  emxFree_real_T(&d_y0);

  /*  Main loop  */
  k = 0;
  emxInit_real_T1(sp, &s1, 1, &s_emlrtRTEI, true);
  emxInit_real_T1(sp, &s2, 1, &t_emlrtRTEI, true);
  emxInit_real_T1(sp, &s3, 1, &u_emlrtRTEI, true);
  emxInit_real_T1(sp, &s4, 1, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &dyout, 2, &x_emlrtRTEI, true);
  emxInit_boolean_T(sp, &x, 2, &r_emlrtRTEI, true);
  emxInit_boolean_T1(sp, &r5, 1, &r_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_ynew, 1, &r_emlrtRTEI, true);
  emxInit_real_T1(sp, &c_ynew, 1, &r_emlrtRTEI, true);
  emxInit_real_T1(sp, &d_ynew, 1, &r_emlrtRTEI, true);
  emxInit_real_T1(sp, &e_ynew, 1, &r_emlrtRTEI, true);
  emxInit_real_T(sp, &b_yout, 2, &r_emlrtRTEI, true);
  emxInit_real_T(sp, &c_yout, 2, &r_emlrtRTEI, true);
  guard1 = false;
  do {
    exitg1 = 0;
    nm1d2 = r3->size[1];
    if (k <= nm1d2 - 2) {
      /* Runge-Kutta 4th order function evaluations */
      i8 = e_ynew->size[0];
      e_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)e_ynew, i8, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      nm1d2 = ynew->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        e_ynew->data[i8] = ynew->data[i8];
      }

      st.site = &xb_emlrtRSI;
      eom(&st, t, e_ynew, nx0, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar,
          DNA_Spar, DNA_Ppar, DNA_Pmpar, s1);
      ndbl = h / 2.0;
      i8 = s4->size[0];
      s4->size[0] = s1->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)s4, i8, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      nm1d2 = s1->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        s4->data[i8] = ndbl * s1->data[i8];
      }

      i8 = ynew->size[0];
      nm1d2 = s4->size[0];
      if (i8 != nm1d2) {
        emlrtSizeEqCheck1DR2012b(i8, nm1d2, &j_emlrtECI, sp);
      }

      i8 = d_ynew->size[0];
      d_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)d_ynew, i8, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      nm1d2 = ynew->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        d_ynew->data[i8] = ynew->data[i8] + s4->data[i8];
      }

      st.site = &yb_emlrtRSI;
      eom(&st, t + h / 2.0, d_ynew, nx0, DNA_incstr, DNA_edgelabel, DNA_Mpar,
          DNA_Hpar, DNA_Spar, DNA_Ppar, DNA_Pmpar, s2);
      ndbl = h / 2.0;
      i8 = s4->size[0];
      s4->size[0] = s2->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)s4, i8, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      nm1d2 = s2->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        s4->data[i8] = ndbl * s2->data[i8];
      }

      i8 = ynew->size[0];
      nm1d2 = s4->size[0];
      if (i8 != nm1d2) {
        emlrtSizeEqCheck1DR2012b(i8, nm1d2, &i_emlrtECI, sp);
      }

      i8 = c_ynew->size[0];
      c_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)c_ynew, i8, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      nm1d2 = ynew->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        c_ynew->data[i8] = ynew->data[i8] + s4->data[i8];
      }

      st.site = &ac_emlrtRSI;
      eom(&st, t + h / 2.0, c_ynew, nx0, DNA_incstr, DNA_edgelabel, DNA_Mpar,
          DNA_Hpar, DNA_Spar, DNA_Ppar, DNA_Pmpar, s3);
      i8 = s4->size[0];
      s4->size[0] = s3->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)s4, i8, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      nm1d2 = s3->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        s4->data[i8] = h * s3->data[i8];
      }

      i8 = ynew->size[0];
      nm1d2 = s4->size[0];
      if (i8 != nm1d2) {
        emlrtSizeEqCheck1DR2012b(i8, nm1d2, &h_emlrtECI, sp);
      }

      i8 = b_ynew->size[0];
      b_ynew->size[0] = ynew->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)b_ynew, i8, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      nm1d2 = ynew->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        b_ynew->data[i8] = ynew->data[i8] + s4->data[i8];
      }

      st.site = &bc_emlrtRSI;
      eom(&st, t + h, b_ynew, nx0, DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar,
          DNA_Spar, DNA_Ppar, DNA_Pmpar, s4);
      i8 = s2->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)s2, i8, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      nm1d2 = s2->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        s2->data[i8] *= 2.0;
      }

      i8 = s1->size[0];
      nm1d2 = s2->size[0];
      if (i8 != nm1d2) {
        emlrtSizeEqCheck1DR2012b(i8, nm1d2, &g_emlrtECI, sp);
      }

      i8 = s3->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)s3, i8, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      nm1d2 = s3->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        s3->data[i8] *= 2.0;
      }

      i8 = s1->size[0];
      nm1d2 = s3->size[0];
      if (i8 != nm1d2) {
        emlrtSizeEqCheck1DR2012b(i8, nm1d2, &g_emlrtECI, sp);
      }

      i8 = s1->size[0];
      nm1d2 = s4->size[0];
      if (i8 != nm1d2) {
        emlrtSizeEqCheck1DR2012b(i8, nm1d2, &g_emlrtECI, sp);
      }

      ndbl = h / 6.0;
      i8 = s1->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)s1, i8, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      nm1d2 = s1->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        s1->data[i8] = ndbl * (((s1->data[i8] + s2->data[i8]) + s3->data[i8]) +
          s4->data[i8]);
      }

      i8 = ynew->size[0];
      nm1d2 = s1->size[0];
      if (i8 != nm1d2) {
        emlrtSizeEqCheck1DR2012b(i8, nm1d2, &f_emlrtECI, sp);
      }

      i8 = ynew->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)ynew, i8, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      nm1d2 = ynew->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        ynew->data[i8] += s1->data[i8];
      }

      tnew = t + h;

      /* Update variables */
      t = tnew;
      i8 = tout->size[0];
      nm1d2 = 2 + k;
      if (!((nm1d2 >= 1) && (nm1d2 <= i8))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, i8, &oc_emlrtBCI, sp);
      }

      tout->data[nm1d2 - 1] = tnew;
      i8 = yout->size[0];
      nm1d2 = (int32_T)(2.0 + (real_T)k);
      if (!((nm1d2 >= 1) && (nm1d2 <= i8))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, i8, &mc_emlrtBCI, sp);
      }

      nm1d2 = yout->size[1];
      i8 = r4->size[0];
      r4->size[0] = nm1d2;
      emxEnsureCapacity(sp, (emxArray__common *)r4, i8, (int32_T)sizeof(int32_T),
                        &r_emlrtRTEI);
      for (i8 = 0; i8 < nm1d2; i8++) {
        r4->data[i8] = i8;
      }

      iv7[0] = 1;
      iv7[1] = r4->size[0];
      iv8[0] = 1;
      iv8[1] = ynew->size[0];
      emlrtSubAssignSizeCheckR2012b(iv7, 2, iv8, 2, &d_emlrtECI, sp);
      nm1d2 = ynew->size[0];
      for (i8 = 0; i8 < nm1d2; i8++) {
        yout->data[(k + yout->size[0] * r4->data[i8]) + 1] = ynew->data[i8];
      }

      i8 = yout->size[0];
      nm1d2 = (int32_T)(2.0 + (real_T)k);
      if (!((nm1d2 >= 1) && (nm1d2 <= i8))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, i8, &lc_emlrtBCI, sp);
      }

      i8 = yout->size[0];
      nm1d2 = (int32_T)((2.0 + (real_T)k) - 1.0);
      if (!((nm1d2 >= 1) && (nm1d2 <= i8))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, i8, &kc_emlrtBCI, sp);
      }

      nm1d2 = yout->size[1];
      i8 = b_yout->size[0] * b_yout->size[1];
      b_yout->size[0] = 1;
      b_yout->size[1] = nm1d2;
      emxEnsureCapacity(sp, (emxArray__common *)b_yout, i8, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      for (i8 = 0; i8 < nm1d2; i8++) {
        b_yout->data[b_yout->size[0] * i8] = yout->data[(k + yout->size[0] * i8)
          + 1];
      }

      for (i8 = 0; i8 < 2; i8++) {
        d_yout[i8] = b_yout->size[i8];
      }

      nm1d2 = yout->size[1];
      i8 = c_yout->size[0] * c_yout->size[1];
      c_yout->size[0] = 1;
      c_yout->size[1] = nm1d2;
      emxEnsureCapacity(sp, (emxArray__common *)c_yout, i8, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      for (i8 = 0; i8 < nm1d2; i8++) {
        c_yout->data[c_yout->size[0] * i8] = yout->data[k + yout->size[0] * i8];
      }

      for (i8 = 0; i8 < 2; i8++) {
        e_yout[i8] = c_yout->size[i8];
      }

      if ((d_yout[0] != e_yout[0]) || (d_yout[1] != e_yout[1])) {
        emlrtSizeEqCheckNDR2012b(&d_yout[0], &e_yout[0], &c_emlrtECI, sp);
      }

      nm1d2 = yout->size[1];
      i8 = dyout->size[0] * dyout->size[1];
      dyout->size[0] = 1;
      dyout->size[1] = nm1d2;
      emxEnsureCapacity(sp, (emxArray__common *)dyout, i8, (int32_T)sizeof
                        (real_T), &r_emlrtRTEI);
      for (i8 = 0; i8 < nm1d2; i8++) {
        dyout->data[dyout->size[0] * i8] = yout->data[(k + yout->size[0] * i8) +
          1] - yout->data[k + yout->size[0] * i8];
      }

      /* Check for NAN and for large derivatives */
      i8 = r5->size[0];
      r5->size[0] = yout->size[0] * yout->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)r5, i8, (int32_T)sizeof
                        (boolean_T), &r_emlrtRTEI);
      nm1d2 = yout->size[0] * yout->size[1];
      for (i8 = 0; i8 < nm1d2; i8++) {
        r5->data[i8] = muDoubleScalarIsNaN(yout->data[i8]);
      }

      st.site = &cc_emlrtRSI;
      if (any(&st, r5)) {
        guard1 = true;
        exitg1 = 1;
      } else {
        ndbl = (real_T)dyout->size[1] / 2.0;
        if (1.0 > ndbl) {
          nm1d2 = 0;
        } else {
          i8 = dyout->size[1];
          if (!(1 <= i8)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i8, &jc_emlrtBCI, sp);
          }

          i8 = dyout->size[1];
          if (ndbl != muDoubleScalarFloor(ndbl)) {
            emlrtIntegerCheckR2012b(ndbl, &d_emlrtDCI, sp);
          }

          nm1d2 = (int32_T)ndbl;
          if (!(nm1d2 <= i8)) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, i8, &jc_emlrtBCI, sp);
          }
        }

        st.site = &cc_emlrtRSI;
        i8 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = nm1d2;
        emxEnsureCapacity(&st, (emxArray__common *)x, i8, (int32_T)sizeof
                          (boolean_T), &r_emlrtRTEI);
        for (i8 = 0; i8 < nm1d2; i8++) {
          x->data[x->size[0] * i8] = (dyout->data[i8] > 10.0);
        }

        b_st.site = &ud_emlrtRSI;
        n_too_large = !isequal(x);
        if (n_too_large) {
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &yc_emlrtRTEI,
            "Coder:toolbox:eml_all_or_any_specialEmpty", 0);
        }

        if ((x->size[1] == 1) || (x->size[1] != 1)) {
          n_too_large = true;
        } else {
          n_too_large = false;
        }

        if (n_too_large) {
        } else {
          emlrtErrorWithMessageIdR2012b(&b_st, &xc_emlrtRTEI,
            "Coder:toolbox:eml_all_or_any_autoDimIncompatibility", 0);
        }

        y = false;
        c_st.site = &vd_emlrtRSI;
        nm1d2 = 1;
        exitg2 = false;
        while ((!exitg2) && (nm1d2 <= x->size[1])) {
          n_too_large = !x->data[nm1d2 - 1];
          if (!n_too_large) {
            y = true;
            exitg2 = true;
          } else {
            nm1d2++;
          }
        }

        if (y) {
          guard1 = true;
          exitg1 = 1;
        } else {
          k++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }

          guard1 = false;
        }
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (guard1) {
    *flag = 0.0;
  }

  emxFree_real_T(&c_yout);
  emxFree_real_T(&b_yout);
  emxFree_real_T(&e_ynew);
  emxFree_real_T(&d_ynew);
  emxFree_real_T(&c_ynew);
  emxFree_real_T(&b_ynew);
  emxFree_boolean_T(&r5);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r4);
  emxFree_real_T(&r3);
  emxFree_real_T(&dyout);
  emxFree_real_T(&ynew);
  emxFree_real_T(&s4);
  emxFree_real_T(&s3);
  emxFree_real_T(&s2);
  emxFree_real_T(&s1);

  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (rk4.c) */
