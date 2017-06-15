/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "error.h"
#include "str2inc.h"
#include "simulateDNA_mexutil.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
void error(const emlrtStack *sp)
{
  char_T u[78];
  static const char_T varargin_1[78] = { 'Y', 'o', 'u', ' ', 'c', 'a', 'n', ' ',
    'o', 'n', 'l', 'y', ' ', 'u', 's', 'e', ' ', 'e', 'd', 'g', 'e', ' ', '3',
    ',', ' ', 'i', '.', 'e', '.', ' ', 'p', 'e', 'n', 'd', 'u', 'l', 'u', 'm',
    ' ', 'o', 'n', ' ', 'c', 'a', 'r', 't', ',', ' ', 'i', 'f', ' ', 'i', 't',
    ' ', 'i', 's', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'd', ' ', 't',
    'o', ' ', 'a', ' ', 'g', 'r', 'o', 'u', 'n', 'd' };

  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv25[2] = { 1, 78 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  memcpy(&u[0], &varargin_1[0], 78U * sizeof(char_T));
  y = NULL;
  m2 = emlrtCreateCharArray(2, iv25);
  emlrtInitCharArrayR2013a(sp, 78, m2, &u[0]);
  emlrtAssign(&y, m2);
  st.site = &nh_emlrtRSI;
  g_error(&st, y, &emlrtMCI);
}

/* End of code generation (error.c) */
