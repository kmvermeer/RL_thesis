/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "xgetrf.h"
#include "simulateDNA_emxutil.h"
#include "error1.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo ke_emlrtRSI = { 25, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRSInfo le_emlrtRSI = { 88, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRSInfo me_emlrtRSI = { 55, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRTEInfo lb_emlrtRTEI = { 1, 26, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRTEInfo jc_emlrtRTEI = { 55, 5, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, emxArray_real_T *A,
            int32_T lda, emxArray_int32_T *ipiv, int32_T *info)
{
  int32_T NPIV;
  int32_T k;
  int32_T b_info;
  emxArray_ptrdiff_t *ipiv_t;
  ptrdiff_t info_t;
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
  st.site = &ke_emlrtRSI;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    k = ipiv->size[0] * ipiv->size[1];
    ipiv->size[0] = 1;
    ipiv->size[1] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)ipiv, k, (int32_T)sizeof(int32_T),
                      &lb_emlrtRTEI);
    b_info = 0;
  } else {
    NPIV = muIntScalarMin_sint32(m, n);
    NPIV = muIntScalarMax_sint32(NPIV, 1);
    b_st.site = &me_emlrtRSI;
    emxInit_ptrdiff_t(&b_st, &ipiv_t, 1, &jc_emlrtRTEI, true);
    k = ipiv_t->size[0];
    ipiv_t->size[0] = NPIV;
    emxEnsureCapacity(&st, (emxArray__common *)ipiv_t, k, (int32_T)sizeof
                      (ptrdiff_t), &lb_emlrtRTEI);
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)m, (ptrdiff_t)n, &A->data[0],
      (ptrdiff_t)lda, &ipiv_t->data[0]);
    b_info = (int32_T)info_t;
    k = ipiv->size[0] * ipiv->size[1];
    ipiv->size[0] = 1;
    ipiv->size[1] = ipiv_t->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)ipiv, k, (int32_T)sizeof(int32_T),
                      &lb_emlrtRTEI);
    NPIV = ipiv->size[1];
    b_st.site = &le_emlrtRSI;
    if (b_info < 0) {
      if (b_info == -1010) {
        c_st.site = &oe_emlrtRSI;
        b_error(&c_st);
      } else {
        c_st.site = &pe_emlrtRSI;
        c_error(&c_st, b_info);
      }
    }

    for (k = 0; k < NPIV; k++) {
      ipiv->data[k] = (int32_T)ipiv_t->data[k];
    }

    emxFree_ptrdiff_t(&ipiv_t);
  }

  *info = b_info;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (xgetrf.c) */
