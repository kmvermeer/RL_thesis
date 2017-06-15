/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * simulateDNA_initialize.c
 *
 * Code generation for function 'simulateDNA_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "simulateDNA_initialize.h"
#include "_coder_simulateDNA_mex.h"
#include "simulateDNA_data.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
void simulateDNA_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (simulateDNA_initialize.c) */
