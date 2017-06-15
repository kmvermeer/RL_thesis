/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: getForces.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 17-Oct-2016 17:50:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "simulateDNA.h"
#include "getForces.h"
#include "MMtorsion.h"
#include "any.h"
#include "simulateDNA_emxutil.h"
#include "DNA2inc.h"
#include "sum.h"
#include "getCompoints.h"

/* Function Definitions */

/*
 * nX  = length(state)/2;              %Get the number of coordinates
 *  X  = state(1:nX);
 *  Xd = state(nX+1:end);               %Get the velocity vector
 * Arguments    : double t
 *                const emxArray_real_T *state
 *                const emxArray_real_T *DNA_incstr
 *                const emxArray_real_T *DNA_edgelabel
 *                const emxArray_real_T *DNA_Mpar
 *                const emxArray_real_T *DNA_Hpar
 *                const emxArray_real_T *DNA_Spar
 *                const emxArray_real_T *DNA_Ppar
 *                const emxArray_real_T *DNA_Pmpar
 *                emxArray_real_T *F
 * Return Type  : void
 */
void getForces(double t, const emxArray_real_T *state, const emxArray_real_T
               *DNA_incstr, const emxArray_real_T *DNA_edgelabel, const
               emxArray_real_T *DNA_Mpar, const emxArray_real_T *DNA_Hpar, const
               emxArray_real_T *DNA_Spar, const emxArray_real_T *DNA_Ppar, const
               emxArray_real_T *DNA_Pmpar, emxArray_real_T *F)
{
  double y;
  int i13;
  emxArray_real_T *comPoint;
  int i14;
  emxArray_boolean_T *b_DNA_edgelabel;
  int i15;
  int ii;
  int loop_ub;
  emxArray_boolean_T *c_DNA_edgelabel;
  double nH;
  emxArray_real_T *incH;
  emxArray_real_T *incS;
  emxArray_real_T *Fs;
  double nS;
  int idx;
  emxArray_real_T *Fh;
  int k;
  boolean_T x_data[100];
  int ii_data[100];
  emxArray_real_T *Fapply;
  boolean_T exitg2;
  boolean_T guard2 = false;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T massnr_data[100];
  int b_massnr_data[100];
  int massnr_size[1];
  emxArray_boolean_T c_massnr_data;
  boolean_T d_massnr_data[100];
  int b_massnr_size[1];
  emxArray_boolean_T e_massnr_data;
  double b_state[6];
  double in6_idx_2;
  double MMSF[6];
  double in6_idx_1;
  double c_state[6];
  double t3;
  double massnr;
  double t4;
  double dv6[3];
  double t5;
  double MMDT[6];
  double t6;
  double t8;
  double dv7[3];
  double t9;
  double b_Fs[3];
  double t7;
  double t2;
  double t11;
  double t12;
  double t10;
  double t14;
  double t13;
  double t16;
  double t17;
  double t15;
  double b_DNA_Spar[3];
  double t18;
  double t19;
  double t20;
  double t22;
  double t23;
  double t25;
  double t30;
  double t35;
  y = (double)state->size[0] / 2.0;
  if (y + 1.0 > state->size[0]) {
    i13 = -1;
  } else {
    i13 = (int)(y + 1.0) - 2;
  }

  emxInit_real_T(&comPoint, 2);
  getCompoints(DNA_incstr, DNA_edgelabel, DNA_Mpar, DNA_Hpar, DNA_Spar, DNA_Ppar,
               DNA_Pmpar, comPoint);
  if (2 > DNA_Mpar->size[0]) {
    i14 = 0;
  } else {
    i14 = 1;
  }

  emxInit_boolean_T(&b_DNA_edgelabel, 2);

  /* Mass of bodies */
  i15 = DNA_Mpar->size[0] - 2;
  ii = b_DNA_edgelabel->size[0] * b_DNA_edgelabel->size[1];
  b_DNA_edgelabel->size[0] = 1;
  b_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)b_DNA_edgelabel, ii, (int)sizeof
                    (boolean_T));
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  for (ii = 0; ii < loop_ub; ii++) {
    b_DNA_edgelabel->data[ii] = (DNA_edgelabel->data[ii] == 1.0);
  }

  emxInit_boolean_T(&c_DNA_edgelabel, 2);
  nH = sum(b_DNA_edgelabel);
  ii = c_DNA_edgelabel->size[0] * c_DNA_edgelabel->size[1];
  c_DNA_edgelabel->size[0] = 1;
  c_DNA_edgelabel->size[1] = DNA_edgelabel->size[1];
  emxEnsureCapacity((emxArray__common *)c_DNA_edgelabel, ii, (int)sizeof
                    (boolean_T));
  loop_ub = DNA_edgelabel->size[0] * DNA_edgelabel->size[1];
  emxFree_boolean_T(&b_DNA_edgelabel);
  for (ii = 0; ii < loop_ub; ii++) {
    c_DNA_edgelabel->data[ii] = (DNA_edgelabel->data[ii] == 2.0);
  }

  emxInit_real_T(&incH, 2);
  emxInit_real_T(&incS, 2);
  emxInit_real_T1(&Fs, 1);
  nS = sum(c_DNA_edgelabel);

  /* Number of springs */
  b_DNA2inc(DNA_incstr, DNA_edgelabel, incH);
  e_DNA2inc(DNA_incstr, DNA_edgelabel, incS);
  ii = DNA_Mpar->size[0];
  idx = Fs->size[0];
  Fs->size[0] = (int)(3.0 * ((double)ii - 1.0));
  emxEnsureCapacity((emxArray__common *)Fs, idx, (int)sizeof(double));
  loop_ub = (int)(3.0 * ((double)ii - 1.0));
  emxFree_boolean_T(&c_DNA_edgelabel);
  for (ii = 0; ii < loop_ub; ii++) {
    Fs->data[ii] = 0.0;
  }

  emxInit_real_T1(&Fh, 1);
  ii = DNA_Mpar->size[0];
  idx = Fh->size[0];
  Fh->size[0] = (int)(3.0 * ((double)ii - 1.0));
  emxEnsureCapacity((emxArray__common *)Fh, idx, (int)sizeof(double));
  loop_ub = (int)(3.0 * ((double)ii - 1.0));
  for (ii = 0; ii < loop_ub; ii++) {
    Fh->data[ii] = 0.0;
  }

  /* Set torsion springs and hinge friction */
  for (k = 0; k < (int)nH; k++) {
    loop_ub = incH->size[0];
    for (ii = 0; ii < loop_ub; ii++) {
      x_data[ii] = (incH->data[ii + incH->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg2 = false;
    while ((!exitg2) && (ii <= loop_ub)) {
      guard2 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= loop_ub) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        ii++;
      }
    }

    if (loop_ub == 1) {
      if (idx == 0) {
        loop_ub = 0;
      }
    } else if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    for (ii = 0; ii < loop_ub; ii++) {
      b_massnr_data[ii] = ii_data[ii];
    }

    massnr_size[0] = loop_ub;
    for (ii = 0; ii < loop_ub; ii++) {
      massnr_data[ii] = (b_massnr_data[ii] == 1);
    }

    c_massnr_data.data = (boolean_T *)&massnr_data;
    c_massnr_data.size = (int *)&massnr_size;
    c_massnr_data.allocatedSize = 100;
    c_massnr_data.numDimensions = 1;
    c_massnr_data.canFreeData = false;
    if (any(&c_massnr_data)) {
      /* account for ground */
      in6_idx_2 = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0) - 1];

      /* MGTORSION */
      /*     FT1 = MGTORSION(K,THETA0,IN3) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     04-Jul-2016 16:03:32 */
      /* Torsion Spring */
      y = state->data[i13 + (int)(((double)b_massnr_data[1] - 1.0) * 3.0)];

      /* MGTORSION */
      /*     FT1 = MGTORSION(K,THETA0,IN3) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     04-Jul-2016 16:03:32 */
      /* Hinge Damping */
      massnr = ((double)b_massnr_data[1] - 1.0) * 3.0;
      dv6[0] = 0.0;
      dv6[1] = 0.0;
      dv6[2] = DNA_Hpar->data[2 + DNA_Hpar->size[0] * k] * (DNA_Hpar->data[4 +
        DNA_Hpar->size[0] * k] * 2.0 - in6_idx_2 * 2.0) * 0.5;
      dv7[0] = 0.0;
      dv7[1] = 0.0;
      dv7[2] = DNA_Hpar->data[3 + DNA_Hpar->size[0] * k] * (DNA_Hpar->data[4 +
        DNA_Hpar->size[0] * k] * 2.0 - y * 2.0) * 0.5;
      y = ((double)b_massnr_data[1] - 1.0) * 3.0;
      for (ii = 0; ii < 3; ii++) {
        b_Fs[ii] = (Fh->data[(int)(massnr + (-2.0 + (double)ii)) - 1] + dv6[ii])
          + dv7[ii];
      }

      for (ii = 0; ii < 3; ii++) {
        Fh->data[(int)(y + (-2.0 + (double)ii)) - 1] = b_Fs[ii];
      }
    } else {
      /* Torsion spring */
      b_state[0] = state->data[(int)(((double)b_massnr_data[0] - 1.0) * 3.0 -
        2.0) - 1];
      b_state[1] = state->data[(int)(((double)b_massnr_data[0] - 1.0) * 3.0 -
        1.0) - 1];
      b_state[2] = state->data[(int)(((double)b_massnr_data[0] - 1.0) * 3.0) - 1];
      b_state[3] = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0 -
        2.0) - 1];
      b_state[4] = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0 -
        1.0) - 1];
      b_state[5] = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0) - 1];
      MMtorsion(DNA_Hpar->data[2 + DNA_Hpar->size[0] * k], DNA_Hpar->data[4 +
                DNA_Hpar->size[0] * k], b_state, MMSF);

      /* Hinge Damping */
      c_state[0] = state->data[i13 + (int)(((double)b_massnr_data[0] - 1.0) *
        3.0 - 2.0)];
      c_state[1] = state->data[i13 + (int)(((double)b_massnr_data[0] - 1.0) *
        3.0 - 1.0)];
      c_state[2] = state->data[i13 + (int)(((double)b_massnr_data[0] - 1.0) *
        3.0)];
      c_state[3] = state->data[i13 + (int)(((double)b_massnr_data[1] - 1.0) *
        3.0 - 2.0)];
      c_state[4] = state->data[i13 + (int)(((double)b_massnr_data[1] - 1.0) *
        3.0 - 1.0)];
      c_state[5] = state->data[i13 + (int)(((double)b_massnr_data[1] - 1.0) *
        3.0)];
      MMtorsion(DNA_Hpar->data[3 + DNA_Hpar->size[0] * k], 0.0, c_state, MMDT);
      massnr = ((double)b_massnr_data[0] - 1.0) * 3.0;
      y = ((double)b_massnr_data[0] - 1.0) * 3.0;
      for (ii = 0; ii < 3; ii++) {
        b_Fs[ii] = (Fh->data[(int)(massnr + (-2.0 + (double)ii)) - 1] + MMSF[ii])
          + MMDT[ii];
      }

      for (ii = 0; ii < 3; ii++) {
        Fh->data[(int)(y + (-2.0 + (double)ii)) - 1] = b_Fs[ii];
      }

      massnr = ((double)b_massnr_data[1] - 1.0) * 3.0;
      y = ((double)b_massnr_data[1] - 1.0) * 3.0;
      for (ii = 0; ii < 3; ii++) {
        b_Fs[ii] = (Fh->data[(int)(massnr + (-2.0 + (double)ii)) - 1] + MMSF[3 +
                    ii]) + MMDT[3 + ii];
      }

      for (ii = 0; ii < 3; ii++) {
        Fh->data[(int)(y + (-2.0 + (double)ii)) - 1] = b_Fs[ii];
      }

      /*          Fh(mnr2*3,1) = -(X(mnr2*3)-X(mnr1*3))*DNA.Hpar(3,k)-(Xd(mnr2*3)-Xd(mnr1*3))*DNA.Hpar(4,k); */
    }
  }

  emxFree_real_T(&incH);
  for (k = 0; k < (int)nS; k++) {
    loop_ub = incS->size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      x_data[i13] = (incS->data[i13 + incS->size[0] * k] == 1.0);
    }

    idx = 0;
    ii = 1;
    exitg1 = false;
    while ((!exitg1) && (ii <= loop_ub)) {
      guard1 = false;
      if (x_data[ii - 1]) {
        idx++;
        ii_data[idx - 1] = ii;
        if (idx >= loop_ub) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
      }
    }

    if (loop_ub == 1) {
      if (idx == 0) {
        loop_ub = 0;
      }
    } else if (1 > idx) {
      loop_ub = 0;
    } else {
      loop_ub = idx;
    }

    for (i13 = 0; i13 < loop_ub; i13++) {
      b_massnr_data[i13] = ii_data[i13];
    }

    /* Find entries in column */
    b_massnr_size[0] = loop_ub;
    for (i13 = 0; i13 < loop_ub; i13++) {
      d_massnr_data[i13] = (b_massnr_data[i13] == 1);
    }

    e_massnr_data.data = (boolean_T *)&d_massnr_data;
    e_massnr_data.size = (int *)&b_massnr_size;
    e_massnr_data.allocatedSize = 100;
    e_massnr_data.numDimensions = 1;
    e_massnr_data.canFreeData = false;
    if (any(&e_massnr_data)) {
      /* account for ground */
      y = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0 - 2.0) - 1];
      in6_idx_1 = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0 - 1.0)
        - 1];
      in6_idx_2 = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0) - 1];

      /* MGSPRINGFORCE */
      /*     FS1 = MGSPRINGFORCE(IN1,IN2,L0,K,IN5,IN6) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     04-Jul-2016 16:03:30 */
      t3 = cos(in6_idx_2);
      t4 = comPoint->data[((int)((double)b_massnr_data[1] - 1.0) +
                           comPoint->size[0]) - 1] - DNA_Spar->data[3 +
        DNA_Spar->size[0] * k];
      t5 = sin(in6_idx_2);
      t6 = comPoint->data[(int)((double)b_massnr_data[1] - 1.0) - 1] -
        DNA_Spar->data[2 + DNA_Spar->size[0] * k];
      t8 = t3 * t6;
      t9 = t4 * t5;
      t2 = ((DNA_Spar->data[DNA_Spar->size[0] * k] + t8) - t9) - y;
      t11 = t3 * t4;
      t12 = t5 * t6;
      t7 = ((DNA_Spar->data[1 + DNA_Spar->size[0] * k] + t11) + t12) - in6_idx_1;
      t14 = t2 * t2 + t7 * t7;
      t16 = DNA_Spar->data[4 + DNA_Spar->size[0] * k] - sqrt(t14);
      t17 = 1.0 / sqrt(t14);
      massnr = ((double)b_massnr_data[1] - 1.0) * 3.0;
      b_DNA_Spar[0] = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t16 * t17 *
        (((DNA_Spar->data[DNA_Spar->size[0] * k] * 2.0 - y * 2.0) + t3 * t6 *
          2.0) - t4 * t5 * 2.0) * -0.5;
      b_DNA_Spar[1] = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t16 * t17 *
        (((DNA_Spar->data[1 + DNA_Spar->size[0] * k] * 2.0 - in6_idx_1 * 2.0) +
          t3 * t4 * 2.0) + t5 * t6 * 2.0) * -0.5;
      b_DNA_Spar[2] = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t16 * t17 *
        (t2 * (t11 + t12) * 2.0 - t7 * (t8 - t9) * 2.0) * -0.5;
      y = ((double)b_massnr_data[1] - 1.0) * 3.0;
      for (i13 = 0; i13 < 3; i13++) {
        b_Fs[i13] = Fs->data[(int)(massnr + (-2.0 + (double)i13)) - 1] +
          b_DNA_Spar[i13];
      }

      for (i13 = 0; i13 < 3; i13++) {
        Fs->data[(int)(y + (-2.0 + (double)i13)) - 1] = b_Fs[i13];
      }
    } else {
      MMSF[0] = state->data[(int)(((double)b_massnr_data[0] - 1.0) * 3.0 - 2.0)
        - 1];
      MMSF[1] = state->data[(int)(((double)b_massnr_data[0] - 1.0) * 3.0 - 1.0)
        - 1];
      MMSF[2] = state->data[(int)(((double)b_massnr_data[0] - 1.0) * 3.0) - 1];
      MMSF[3] = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0 - 2.0)
        - 1];
      MMSF[4] = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0 - 1.0)
        - 1];
      MMSF[5] = state->data[(int)(((double)b_massnr_data[1] - 1.0) * 3.0) - 1];

      /* MMSPRINGFORCE */
      /*     FS2 = MMSPRINGFORCE(IN1,IN2,L0,K,IN5,IN6,IN7) */
      /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
      /*     04-Jul-2016 16:03:31 */
      t3 = cos(MMSF[2]);
      t4 = comPoint->data[((int)((double)b_massnr_data[0] - 1.0) +
                           comPoint->size[0]) - 1] - DNA_Spar->data[1 +
        DNA_Spar->size[0] * k];
      t5 = cos(MMSF[5]);
      t6 = comPoint->data[((int)((double)b_massnr_data[1] - 1.0) +
                           comPoint->size[0]) - 1] - DNA_Spar->data[3 +
        DNA_Spar->size[0] * k];
      t7 = sin(MMSF[2]);
      t8 = comPoint->data[(int)((double)b_massnr_data[0] - 1.0) - 1] -
        DNA_Spar->data[DNA_Spar->size[0] * k];
      t9 = sin(MMSF[5]);
      t10 = comPoint->data[(int)((double)b_massnr_data[1] - 1.0) - 1] -
        DNA_Spar->data[2 + DNA_Spar->size[0] * k];
      t12 = t3 * t8;
      t13 = t5 * t10;
      t14 = t4 * t7;
      t15 = t6 * t9;
      t2 = ((((-t12 + t13) + t14) - t15) + MMSF[0]) - MMSF[3];
      t17 = t3 * t4;
      t18 = t5 * t6;
      t19 = t7 * t8;
      t20 = t9 * t10;
      t11 = ((((-t17 + t18) - t19) + t20) + MMSF[1]) - MMSF[4];
      t22 = t2 * t2 + t11 * t11;
      t23 = 1.0 / sqrt(t22);
      t25 = DNA_Spar->data[4 + DNA_Spar->size[0] * k] - sqrt(t22);
      t30 = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (((((MMSF[0]
        * 2.0 + t5 * t10 * 2.0) + t4 * t7 * 2.0) - MMSF[3] * 2.0) - t3 * t8 *
        2.0) - t6 * t9 * 2.0) * 0.5;
      t35 = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (((((MMSF[1]
        * 2.0 + t5 * t6 * 2.0) + t9 * t10 * 2.0) - MMSF[4] * 2.0) - t3 * t4 *
        2.0) - t7 * t8 * 2.0) * 0.5;
      MMSF[0] = t30;
      MMSF[1] = t35;
      MMSF[2] = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (t2 *
        (t17 + t19) * 2.0 - t11 * (t12 - t14) * 2.0) * 0.5;
      MMSF[3] = -t30;
      MMSF[4] = -t35;
      MMSF[5] = DNA_Spar->data[5 + DNA_Spar->size[0] * k] * t23 * t25 * (t2 *
        (t18 + t20) * 2.0 - t11 * (t13 - t15) * 2.0) * -0.5;
      massnr = ((double)b_massnr_data[0] - 1.0) * 3.0;
      y = ((double)b_massnr_data[0] - 1.0) * 3.0;
      for (i13 = 0; i13 < 3; i13++) {
        b_Fs[i13] = Fs->data[(int)(massnr + (-2.0 + (double)i13)) - 1] +
          MMSF[i13];
      }

      for (i13 = 0; i13 < 3; i13++) {
        Fs->data[(int)(y + (-2.0 + (double)i13)) - 1] = b_Fs[i13];
      }

      massnr = ((double)b_massnr_data[1] - 1.0) * 3.0;
      y = ((double)b_massnr_data[1] - 1.0) * 3.0;
      for (i13 = 0; i13 < 3; i13++) {
        b_Fs[i13] = Fs->data[(int)(massnr + (-2.0 + (double)i13)) - 1] + MMSF[3
          + i13];
      }

      for (i13 = 0; i13 < 3; i13++) {
        Fs->data[(int)(y + (-2.0 + (double)i13)) - 1] = b_Fs[i13];
      }
    }
  }

  emxFree_real_T(&incS);
  emxFree_real_T(&comPoint);
  emxInit_real_T1(&Fapply, 1);
  i13 = DNA_Mpar->size[0];
  ii = Fapply->size[0];
  Fapply->size[0] = (int)(3.0 * ((double)i13 - 1.0));
  emxEnsureCapacity((emxArray__common *)Fapply, ii, (int)sizeof(double));
  loop_ub = (int)(3.0 * ((double)i13 - 1.0));
  for (i13 = 0; i13 < loop_ub; i13++) {
    Fapply->data[i13] = 0.0;
  }

  if ((2.0 < t) && (t < 4.0)) {
    for (k = 0; k <= i15; k++) {
      Fapply->data[(int)((1.0 + (double)k) * 3.0) - 1] = 0.0;
    }
  }

  i13 = DNA_Mpar->size[0];
  ii = F->size[0];
  F->size[0] = (int)(3.0 * ((double)i13 - 1.0));
  emxEnsureCapacity((emxArray__common *)F, ii, (int)sizeof(double));
  loop_ub = (int)(3.0 * ((double)i13 - 1.0));
  for (i13 = 0; i13 < loop_ub; i13++) {
    F->data[i13] = 0.0;
  }

  for (k = 0; k <= i15; k++) {
    F->data[(int)((1.0 + (double)k) * 3.0 - 1.0) - 1] = -DNA_Mpar->data[(i14 + k)
      + (DNA_Mpar->size[0] << 1)] * 9.81;
  }

  i13 = F->size[0];
  emxEnsureCapacity((emxArray__common *)F, i13, (int)sizeof(double));
  loop_ub = F->size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    F->data[i13] = ((F->data[i13] + Fs->data[i13]) + Fh->data[i13]) +
      Fapply->data[i13];
  }

  emxFree_real_T(&Fapply);
  emxFree_real_T(&Fh);
  emxFree_real_T(&Fs);
}

/*
 * File trailer for getForces.c
 *
 * [EOF]
 */
