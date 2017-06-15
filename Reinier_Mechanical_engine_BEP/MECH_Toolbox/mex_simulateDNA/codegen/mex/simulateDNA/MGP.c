/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MGP.c
 *
 * Code generation for function 'MGP'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "MGP.h"
#include "blas.h"
#include "lapacke.h"

/* Function Definitions */
real_T MGP(const real_T in1[2], real_T alpha, const real_T in3[2], const real_T
           in4[3])
{
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;

  /* MGP */
  /*     C3 = MGP(IN1,ALPHA,IN3,IN4) */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     17-Oct-2016 18:51:21 */
  t2 = muDoubleScalarCos(in4[2]);
  t3 = in1[1] - in3[1];
  t4 = muDoubleScalarSin(in4[2]);
  t5 = in1[0] - in3[0];
  return -muDoubleScalarCos(alpha) * (((-in1[1] + in4[1]) + t2 * t3) + t4 * t5)
    - muDoubleScalarSin(alpha) * (((in1[0] - in4[0]) - t2 * t5) + t3 * t4);
}

/* End of code generation (MGP.c) */
