/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * simulateDNA_mexutil.c
 *
 * Code generation for function 'simulateDNA_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "simulateDNA_mexutil.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m9;
  y = NULL;
  m9 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m9);
  return y;
}

void g_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

/* End of code generation (simulateDNA_mexutil.c) */
