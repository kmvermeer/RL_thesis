/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "mldivide.h"
#include "simulateDNA_emxutil.h"
#include "error1.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "xgetrf.h"
#include "qrsolve.h"
#include "xgeqp3.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo xe_emlrtRSI = { 68, "xtrsm",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"
};

static emlrtRSInfo hh_emlrtRSI = { 1, "mldivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

static emlrtRSInfo ih_emlrtRSI = { 131, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo jh_emlrtRSI = { 142, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo kh_emlrtRSI = { 144, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRTEInfo cc_emlrtRTEI = { 1, 2, "mldivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

static emlrtRTEInfo id_emlrtRTEI = { 1, 1, "mldivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const emxArray_real_T *A, const
              emxArray_real_T *B, emxArray_real_T *Y)
{
  emxArray_real_T *b_A;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  emxArray_real_T *b_B;
  uint32_T unnamed_idx_0;
  int32_T i;
  int32_T mn;
  int32_T rankA;
  real_T temp;
  char_T DIAGA;
  ptrdiff_t nrc_t;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 2, &cc_emlrtRTEI, true);
  if (B->size[0] == A->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &id_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  emxInit_real_T1(sp, &tau, 1, &cc_emlrtRTEI, true);
  emxInit_int32_T(sp, &jpvt, 2, &cc_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_B, 1, &cc_emlrtRTEI, true);
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0)) {
    unnamed_idx_0 = (uint32_T)A->size[1];
    i = Y->size[0];
    Y->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity(sp, (emxArray__common *)Y, i, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    mn = (int32_T)unnamed_idx_0;
    for (i = 0; i < mn; i++) {
      Y->data[i] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    st.site = &hh_emlrtRSI;
    b_st.site = &ee_emlrtRSI;
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)b_A, i, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    mn = A->size[0] * A->size[1];
    for (i = 0; i < mn; i++) {
      b_A->data[i] = A->data[i];
    }

    c_st.site = &ge_emlrtRSI;
    xgetrf(&c_st, A->size[1], A->size[1], b_A, A->size[1], jpvt, &mn);
    if (mn > 0) {
      c_st.site = &fe_emlrtRSI;
      d_st.site = &we_emlrtRSI;
      warning(&d_st);
    }

    i = Y->size[0];
    Y->size[0] = B->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)Y, i, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    mn = B->size[0];
    for (i = 0; i < mn; i++) {
      Y->data[i] = B->data[i];
    }

    c_st.site = &ih_emlrtRSI;
    for (mn = 0; mn + 1 < A->size[1]; mn++) {
      if (jpvt->data[mn] != mn + 1) {
        temp = Y->data[mn];
        Y->data[mn] = Y->data[jpvt->data[mn] - 1];
        Y->data[jpvt->data[mn] - 1] = temp;
      }
    }

    c_st.site = &jh_emlrtRSI;
    d_st.site = &xe_emlrtRSI;
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'L';
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)1;
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)A->size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &Y->data[0], &ldb_t);
    c_st.site = &kh_emlrtRSI;
    d_st.site = &xe_emlrtRSI;
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'L';
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)1;
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)A->size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &Y->data[0], &ldb_t);
  } else {
    st.site = &hh_emlrtRSI;
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)b_A, i, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    mn = A->size[0] * A->size[1];
    for (i = 0; i < mn; i++) {
      b_A->data[i] = A->data[i];
    }

    b_st.site = &ye_emlrtRSI;
    xgeqp3(&b_st, b_A, tau, jpvt);
    b_st.site = &af_emlrtRSI;
    rankA = rankFromQR(&b_st, b_A);
    b_st.site = &bf_emlrtRSI;
    mn = b_A->size[1];
    i = Y->size[0];
    Y->size[0] = mn;
    emxEnsureCapacity(&b_st, (emxArray__common *)Y, i, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    for (i = 0; i < mn; i++) {
      Y->data[i] = 0.0;
    }

    c_st.site = &jf_emlrtRSI;
    d_st.site = &nf_emlrtRSI;
    i = b_B->size[0];
    b_B->size[0] = B->size[0];
    emxEnsureCapacity(&d_st, (emxArray__common *)b_B, i, (int32_T)sizeof(real_T),
                      &cc_emlrtRTEI);
    mn = B->size[0];
    for (i = 0; i < mn; i++) {
      b_B->data[i] = B->data[i];
    }

    mn = muIntScalarMin_sint32(b_A->size[0], b_A->size[1]);
    if (!((b_A->size[0] == 0) || (b_A->size[1] == 0))) {
      nrc_t = (ptrdiff_t)b_B->size[0];
      nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1, (ptrdiff_t)mn,
        &b_A->data[0], (ptrdiff_t)b_A->size[0], &tau->data[0], &b_B->data[0],
        nrc_t);
      mn = (int32_T)nrc_t;
      e_st.site = &of_emlrtRSI;
      if (mn != 0) {
        if (mn == -1010) {
          f_st.site = &oe_emlrtRSI;
          b_error(&f_st);
        } else {
          f_st.site = &pe_emlrtRSI;
          f_error(&f_st, mn);
        }
      }
    }

    c_st.site = &lf_emlrtRSI;
    if ((!(1 > rankA)) && (rankA > 2147483646)) {
      d_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (i = 0; i + 1 <= rankA; i++) {
      Y->data[jpvt->data[i] - 1] = b_B->data[i];
    }

    for (mn = rankA - 1; mn + 1 > 0; mn--) {
      Y->data[jpvt->data[mn] - 1] /= b_A->data[mn + b_A->size[0] * mn];
      c_st.site = &mf_emlrtRSI;
      for (i = 0; i + 1 <= mn; i++) {
        Y->data[jpvt->data[i] - 1] -= Y->data[jpvt->data[mn] - 1] * b_A->data[i
          + b_A->size[0] * mn];
      }
    }
  }

  emxFree_real_T(&b_B);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mldivide.c) */
