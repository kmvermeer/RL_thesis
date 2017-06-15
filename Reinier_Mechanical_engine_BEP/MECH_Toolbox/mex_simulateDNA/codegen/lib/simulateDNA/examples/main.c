/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "main.h"
#include "simulateDNA_terminate.h"
#include "simulateDNA_emxAPI.h"
#include "simulateDNA_initialize.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static emxArray_real_T *argInit_3xUnbounded_real_T(void);
static emxArray_real_T *argInit_5xUnbounded_real_T(void);
static emxArray_real_T *argInit_6xUnbounded_real_T(void);
static emxArray_real_T *argInit_Unboundedx2_real_T(void);
static emxArray_real_T *argInit_Unboundedx3_real_T(void);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static void main_simulateDNA(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv3[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv3);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_3xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv7[2] = { 3, 2 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv7);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_5xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv5[2] = { 5, 2 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv5);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_6xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv6[2] = { 6, 2 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv6);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 6; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx2_real_T(void)
{
  emxArray_real_T *result;
  static int iv8[2] = { 2, 2 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv8);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx3_real_T(void)
{
  emxArray_real_T *result;
  static int iv4[2] = { 2, 3 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv4);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 3; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->incstr = argInit_1xUnbounded_real_T();
  result->edgelabel = argInit_1xUnbounded_real_T();
  result->Mpar = argInit_Unboundedx3_real_T();
  result->Hpar = argInit_5xUnbounded_real_T();
  result->Spar = argInit_6xUnbounded_real_T();
  result->Ppar = argInit_3xUnbounded_real_T();
  result->Pmpar = argInit_5xUnbounded_real_T();
  result->fitness = argInit_real_T();
  result->bestTrajectory = argInit_Unboundedx2_real_T();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_simulateDNA(void)
{
  emxArray_real_T *t;
  emxArray_real_T *qss;
  struct0_T DNA;
  double flag;
  emxInitArray_real_T(&t, 1);
  emxInitArray_real_T(&qss, 2);

  /* Initialize function 'simulateDNA' input arguments. */
  /* Initialize function input argument 'DNA'. */
  argInit_struct0_T(&DNA);

  /* Call the entry-point 'simulateDNA'. */
  simulateDNA(&DNA, argInit_real_T(), argInit_real_T(), t, qss, &flag);
  emxDestroyArray_real_T(qss);
  emxDestroyArray_real_T(t);
  emxDestroy_struct0_T(DNA);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  simulateDNA_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_simulateDNA();

  /* Terminate the application.
     You do not need to do this more than one time. */
  simulateDNA_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
