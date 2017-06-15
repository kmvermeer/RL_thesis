/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "warning.h"
#include "blas.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 14, 25, "warning",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo c_emlrtMCI = { 14, 9, "warning",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtRSInfo lh_emlrtRSI = { 14, "warning",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m14;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m14, 4, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m12;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m12, 2, pArrays, "feval", true, location);
}

void b_warning(const emlrtStack *sp, int32_T varargin_1, const char_T
               varargin_2[14])
{
  int32_T i25;
  const mxArray *y;
  char_T u[7];
  static const char_T cv3[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m6;
  static const int32_T iv41[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv4[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv42[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[32];
  static const char_T msgID[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
    'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  static const int32_T iv43[2] = { 1, 32 };

  const mxArray *d_y;
  const mxArray *e_y;
  char_T d_u[14];
  static const int32_T iv44[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i25 = 0; i25 < 7; i25++) {
    u[i25] = cv3[i25];
  }

  y = NULL;
  m6 = emlrtCreateCharArray(2, iv41);
  emlrtInitCharArrayR2013a(sp, 7, m6, &u[0]);
  emlrtAssign(&y, m6);
  for (i25 = 0; i25 < 7; i25++) {
    b_u[i25] = cv4[i25];
  }

  b_y = NULL;
  m6 = emlrtCreateCharArray(2, iv42);
  emlrtInitCharArrayR2013a(sp, 7, m6, &b_u[0]);
  emlrtAssign(&b_y, m6);
  for (i25 = 0; i25 < 32; i25++) {
    c_u[i25] = msgID[i25];
  }

  c_y = NULL;
  m6 = emlrtCreateCharArray(2, iv43);
  emlrtInitCharArrayR2013a(sp, 32, m6, &c_u[0]);
  emlrtAssign(&c_y, m6);
  d_y = NULL;
  m6 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m6) = varargin_1;
  emlrtAssign(&d_y, m6);
  for (i25 = 0; i25 < 14; i25++) {
    d_u[i25] = varargin_2[i25];
  }

  e_y = NULL;
  m6 = emlrtCreateCharArray(2, iv44);
  emlrtInitCharArrayR2013a(sp, 14, m6, &d_u[0]);
  emlrtAssign(&e_y, m6);
  st.site = &lh_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, e_y, &b_emlrtMCI), &c_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  int32_T i24;
  const mxArray *y;
  char_T u[7];
  static const char_T cv0[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m4;
  static const int32_T iv37[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv38[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[27];
  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  static const int32_T iv39[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i24 = 0; i24 < 7; i24++) {
    u[i24] = cv0[i24];
  }

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv37);
  emlrtInitCharArrayR2013a(sp, 7, m4, &u[0]);
  emlrtAssign(&y, m4);
  for (i24 = 0; i24 < 7; i24++) {
    b_u[i24] = cv1[i24];
  }

  b_y = NULL;
  m4 = emlrtCreateCharArray(2, iv38);
  emlrtInitCharArrayR2013a(sp, 7, m4, &b_u[0]);
  emlrtAssign(&b_y, m4);
  for (i24 = 0; i24 < 27; i24++) {
    c_u[i24] = msgID[i24];
  }

  c_y = NULL;
  m4 = emlrtCreateCharArray(2, iv39);
  emlrtInitCharArrayR2013a(sp, 27, m4, &c_u[0]);
  emlrtAssign(&c_y, m4);
  st.site = &lh_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &b_emlrtMCI), &c_emlrtMCI);
}

/* End of code generation (warning.c) */
