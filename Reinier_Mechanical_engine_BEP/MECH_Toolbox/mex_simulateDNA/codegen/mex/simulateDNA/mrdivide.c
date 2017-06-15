/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide.c
 *
 * Code generation for function 'mrdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "mrdivide.h"
#include "simulateDNA_emxutil.h"
#include "lusolve.h"
#include "qrsolve.h"
#include "xgeqp3.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo de_emlrtRSI = { 1, "mrdivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"
};

static emlrtRTEInfo jb_emlrtRTEI = { 1, 2, "mrdivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"
};

static emlrtRTEInfo ed_emlrtRTEI = { 1, 1, "mrdivide",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"
};

/* Function Definitions */
void mrdivide(const emlrtStack *sp, const emxArray_real_T *A, const
              emxArray_real_T *B, emxArray_real_T *y)
{
  emxArray_real_T *b_A;
  emxArray_real_T *Y;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  emxArray_real_T *c_A;
  uint32_T unnamed_idx_0;
  uint32_T unnamed_idx_1;
  int32_T i22;
  int32_T loop_ub;
  int32_T b_loop_ub;
  int32_T rankR;
  int32_T i23;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 2, &jb_emlrtRTEI, true);
  if (B->size[1] == A->size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ed_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  emxInit_real_T(sp, &Y, 2, &jb_emlrtRTEI, true);
  emxInit_real_T1(sp, &tau, 1, &jb_emlrtRTEI, true);
  emxInit_int32_T(sp, &jpvt, 2, &jb_emlrtRTEI, true);
  emxInit_real_T(sp, &c_A, 2, &jb_emlrtRTEI, true);
  if ((A->size[0] == 0) || (A->size[1] == 0) || ((B->size[0] == 0) || (B->size[1]
        == 0))) {
    unnamed_idx_0 = (uint32_T)A->size[0];
    unnamed_idx_1 = (uint32_T)B->size[0];
    i22 = y->size[0] * y->size[1];
    y->size[0] = (int32_T)unnamed_idx_0;
    y->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(sp, (emxArray__common *)y, i22, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
    for (i22 = 0; i22 < loop_ub; i22++) {
      y->data[i22] = 0.0;
    }
  } else if (B->size[0] == B->size[1]) {
    st.site = &de_emlrtRSI;
    lusolve(&st, B, A, y);
  } else {
    st.site = &de_emlrtRSI;
    i22 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = B->size[1];
    b_A->size[1] = B->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)b_A, i22, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    loop_ub = B->size[0];
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_loop_ub = B->size[1];
      for (i23 = 0; i23 < b_loop_ub; i23++) {
        b_A->data[i23 + b_A->size[0] * i22] = B->data[i22 + B->size[0] * i23];
      }
    }

    b_st.site = &ye_emlrtRSI;
    xgeqp3(&b_st, b_A, tau, jpvt);
    b_st.site = &af_emlrtRSI;
    rankR = rankFromQR(&b_st, b_A);
    i22 = c_A->size[0] * c_A->size[1];
    c_A->size[0] = A->size[1];
    c_A->size[1] = A->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)c_A, i22, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    loop_ub = A->size[0];
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_loop_ub = A->size[1];
      for (i23 = 0; i23 < b_loop_ub; i23++) {
        c_A->data[i23 + c_A->size[0] * i22] = A->data[i22 + A->size[0] * i23];
      }
    }

    b_st.site = &bf_emlrtRSI;
    LSQFromQR(&b_st, b_A, tau, jpvt, c_A, rankR, Y);
    i22 = y->size[0] * y->size[1];
    y->size[0] = Y->size[1];
    y->size[1] = Y->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)y, i22, (int32_T)sizeof(real_T),
                      &jb_emlrtRTEI);
    loop_ub = Y->size[0];
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_loop_ub = Y->size[1];
      for (i23 = 0; i23 < b_loop_ub; i23++) {
        y->data[i23 + y->size[0] * i22] = Y->data[i22 + Y->size[0] * i23];
      }
    }
  }

  emxFree_real_T(&c_A);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&Y);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mrdivide.c) */
