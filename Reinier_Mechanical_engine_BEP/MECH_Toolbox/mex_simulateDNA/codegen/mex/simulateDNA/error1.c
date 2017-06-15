/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error1.c
 *
 * Code generation for function 'error1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "error1.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRTEInfo fd_emlrtRTEI = { 17, 9, "error",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\error.m"
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &fd_emlrtRTEI, "MATLAB:nomem", 0);
}

void c_error(const emlrtStack *sp, int32_T varargin_2)
{
  emlrtErrorWithMessageIdR2012b(sp, &fd_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, "LAPACKE_dgetrf_work", 12,
    varargin_2);
}

void d_error(const emlrtStack *sp, int32_T varargin_2)
{
  emlrtErrorWithMessageIdR2012b(sp, &fd_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, "LAPACKE_dgeqp3", 12,
    varargin_2);
}

void e_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &fd_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
}

void f_error(const emlrtStack *sp, int32_T varargin_2)
{
  emlrtErrorWithMessageIdR2012b(sp, &fd_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, "LAPACKE_dormqr", 12,
    varargin_2);
}

/* End of code generation (error1.c) */
