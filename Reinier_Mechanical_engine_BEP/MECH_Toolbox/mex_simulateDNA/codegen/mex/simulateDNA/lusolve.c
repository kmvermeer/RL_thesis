/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lusolve.c
 *
 * Code generation for function 'lusolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "lusolve.h"
#include "simulateDNA_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "xgetrf.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo he_emlrtRSI = { 114, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo ie_emlrtRSI = { 116, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo je_emlrtRSI = { 121, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRTEInfo kb_emlrtRTEI = { 1, 19, "lusolve",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

/* Function Definitions */
void lusolve(const emlrtStack *sp, const emxArray_real_T *A, const
             emxArray_real_T *B, emxArray_real_T *X)
{
  emxArray_real_T *b_A;
  int32_T info;
  int32_T jp;
  emxArray_int32_T *ipiv;
  int32_T nb;
  real_T temp;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  int32_T xi;
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
  emxInit_real_T(sp, &b_A, 2, &kb_emlrtRTEI, true);
  st.site = &ee_emlrtRSI;
  info = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_A, info, (int32_T)sizeof(real_T),
                    &kb_emlrtRTEI);
  jp = A->size[0] * A->size[1];
  for (info = 0; info < jp; info++) {
    b_A->data[info] = A->data[info];
  }

  emxInit_int32_T(&st, &ipiv, 2, &kb_emlrtRTEI, true);
  b_st.site = &ge_emlrtRSI;
  xgetrf(&b_st, A->size[1], A->size[1], b_A, A->size[1], ipiv, &info);
  if (info > 0) {
    b_st.site = &fe_emlrtRSI;
    c_st.site = &we_emlrtRSI;
    warning(&c_st);
  }

  nb = B->size[0];
  b_st.site = &he_emlrtRSI;
  info = X->size[0] * X->size[1];
  X->size[0] = B->size[0];
  X->size[1] = B->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)X, info, (int32_T)sizeof(real_T),
                    &kb_emlrtRTEI);
  jp = B->size[0] * B->size[1];
  for (info = 0; info < jp; info++) {
    X->data[info] = B->data[info];
  }

  if ((B->size[0] < 1) || (A->size[1] < 1)) {
  } else {
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'R';
    m_t = (ptrdiff_t)B->size[0];
    n_t = (ptrdiff_t)A->size[1];
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)B->size[0];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &X->data[0], &ldb_t);
  }

  b_st.site = &ie_emlrtRSI;
  if ((B->size[0] < 1) || (A->size[1] < 1)) {
  } else {
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'R';
    m_t = (ptrdiff_t)B->size[0];
    n_t = (ptrdiff_t)A->size[1];
    lda_t = (ptrdiff_t)A->size[1];
    ldb_t = (ptrdiff_t)B->size[0];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A->data[0],
          &lda_t, &X->data[0], &ldb_t);
  }

  for (info = A->size[1] - 2; info + 1 > 0; info--) {
    if (ipiv->data[info] != info + 1) {
      jp = ipiv->data[info] - 1;
      b_st.site = &je_emlrtRSI;
      if ((!(1 > nb)) && (nb > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (xi = 0; xi + 1 <= nb; xi++) {
        temp = X->data[xi + X->size[0] * info];
        X->data[xi + X->size[0] * info] = X->data[xi + X->size[0] * jp];
        X->data[xi + X->size[0] * jp] = temp;
      }
    }
  }

  emxFree_int32_T(&ipiv);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (lusolve.c) */
