/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "isequal.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 40, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRSInfo vb_emlrtRSI = { 113, "combine_vector_elements",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combine_vector_elements.m"
};

static emlrtRTEInfo uc_emlrtRTEI = { 17, 15, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRTEInfo vc_emlrtRTEI = { 21, 5, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

static emlrtRTEInfo wc_emlrtRTEI = { 30, 5, "mean",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"
};

/* Function Definitions */
void b_mean(const emlrtStack *sp, const emxArray_real_T *x, real_T y[2])
{
  boolean_T b0;
  int32_T vlen;
  int32_T i;
  int32_T xoffset;
  real_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b0 = (x->size[0] != 1);
  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &uc_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  b0 = !b_isequal(x);
  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &vc_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b0 = !b_isequal(x);
  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &wc_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  st.site = &ub_emlrtRSI;
  if (x->size[0] == 0) {
    for (vlen = 0; vlen < 2; vlen++) {
      y[vlen] = 0.0;
    }
  } else {
    vlen = x->size[0];
    for (i = 0; i < 2; i++) {
      xoffset = i * vlen;
      s = x->data[xoffset];
      b_st.site = &vb_emlrtRSI;
      if ((!(2 > vlen)) && (vlen > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (k = 2; k <= vlen; k++) {
        s += x->data[(xoffset + k) - 1];
      }

      y[i] = s;
    }
  }

  i = x->size[0];
  for (vlen = 0; vlen < 2; vlen++) {
    y[vlen] /= (real_T)i;
  }
}

void mean(const real_T x[4], real_T y[2])
{
  int32_T i;
  for (i = 0; i < 2; i++) {
    y[i] = (x[i << 1] + x[(i << 1) + 1]) / 2.0;
  }
}

/* End of code generation (mean.c) */
