/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "xgeqp3.h"
#include "error1.h"
#include "simulateDNA_emxutil.h"
#include "colon.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo se_emlrtRSI = { 75, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo te_emlrtRSI = { 112, "colon",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo cf_emlrtRSI = { 14, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo df_emlrtRSI = { 41, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo ef_emlrtRSI = { 76, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRSInfo ff_emlrtRSI = { 79, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo nb_emlrtRTEI = { 1, 25, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

static emlrtRTEInfo kc_emlrtRTEI = { 45, 5, "xgeqp3",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
            emxArray_int32_T *jpvt)
{
  int32_T m;
  int32_T n;
  emxArray_ptrdiff_t *jpvt_t;
  int32_T i58;
  ptrdiff_t m_t;
  boolean_T p;
  boolean_T b_p;
  int32_T loop_ub;
  int32_T i59;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &cf_emlrtRSI;
  m = A->size[0];
  n = A->size[1];
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    i58 = tau->size[0];
    tau->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)tau, i58, (int32_T)sizeof(real_T),
                      &nb_emlrtRTEI);
    b_st.site = &df_emlrtRSI;
    c_st.site = &wd_emlrtRSI;
    d_st.site = &se_emlrtRSI;
    e_st.site = &te_emlrtRSI;
    eml_signed_integer_colon(&e_st, A->size[1], jpvt);
  } else {
    emxInit_ptrdiff_t(&st, &jpvt_t, 1, &kc_emlrtRTEI, true);
    i58 = tau->size[0];
    tau->size[0] = muIntScalarMin_sint32(m, n);
    emxEnsureCapacity(&st, (emxArray__common *)tau, i58, (int32_T)sizeof(real_T),
                      &nb_emlrtRTEI);
    i58 = jpvt_t->size[0];
    jpvt_t->size[0] = A->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)jpvt_t, i58, (int32_T)sizeof
                      (ptrdiff_t), &nb_emlrtRTEI);
    m = A->size[1];
    for (i58 = 0; i58 < m; i58++) {
      jpvt_t->data[i58] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)A->size[0];
    m_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
                         &jpvt_t->data[0], &tau->data[0]);
    m = (int32_T)m_t;
    b_st.site = &ef_emlrtRSI;
    if (m != 0) {
      p = true;
      b_p = false;
      if (m == -4) {
        b_p = true;
      }

      if (!b_p) {
        if (m == -1010) {
          c_st.site = &oe_emlrtRSI;
          b_error(&c_st);
        } else {
          c_st.site = &pe_emlrtRSI;
          d_error(&c_st, m);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      i58 = A->size[0] * A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)A, i58, (int32_T)sizeof(real_T),
                        &nb_emlrtRTEI);
      m = A->size[1];
      for (i58 = 0; i58 < m; i58++) {
        loop_ub = A->size[0];
        for (i59 = 0; i59 < loop_ub; i59++) {
          A->data[i59 + A->size[0] * i58] = rtNaN;
        }
      }

      m = tau->size[0];
      i58 = tau->size[0];
      tau->size[0] = m;
      emxEnsureCapacity(&st, (emxArray__common *)tau, i58, (int32_T)sizeof
                        (real_T), &nb_emlrtRTEI);
      for (i58 = 0; i58 < m; i58++) {
        tau->data[i58] = rtNaN;
      }

      b_st.site = &ff_emlrtRSI;
      c_st.site = &wd_emlrtRSI;
      d_st.site = &se_emlrtRSI;
      e_st.site = &te_emlrtRSI;
      eml_signed_integer_colon(&e_st, n, jpvt);
    } else {
      i58 = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = jpvt_t->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)jpvt, i58, (int32_T)sizeof
                        (int32_T), &nb_emlrtRTEI);
      m = jpvt_t->size[0];
      for (i58 = 0; i58 < m; i58++) {
        jpvt->data[jpvt->size[0] * i58] = (int32_T)jpvt_t->data[i58];
      }
    }

    emxFree_ptrdiff_t(&jpvt_t);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgeqp3.c) */
