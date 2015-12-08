// File Automatically generated by eLiSe
#include "StdAfx.h"


class cGen2DBundleEgProj_Deg5: public cElCompiledFonc
{
   public :

      cGen2DBundleEgProj_Deg5();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetAmplApp(double);
      void SetCentrApp_x(double);
      void SetCentrApp_y(double);
      void SetGradX_x(double);
      void SetGradX_y(double);
      void SetGradY_x(double);
      void SetGradY_y(double);
      void SetGradZ_x(double);
      void SetGradZ_y(double);
      void SetPIm_x(double);
      void SetPIm_y(double);
      void SetPTerInit_x(double);
      void SetPTerInit_y(double);
      void SetPTerInit_z(double);
      void SetProjInit_x(double);
      void SetProjInit_y(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocAmplApp;
      double mLocCentrApp_x;
      double mLocCentrApp_y;
      double mLocGradX_x;
      double mLocGradX_y;
      double mLocGradY_x;
      double mLocGradY_y;
      double mLocGradZ_x;
      double mLocGradZ_y;
      double mLocPIm_x;
      double mLocPIm_y;
      double mLocPTerInit_x;
      double mLocPTerInit_y;
      double mLocPTerInit_z;
      double mLocProjInit_x;
      double mLocProjInit_y;
};
