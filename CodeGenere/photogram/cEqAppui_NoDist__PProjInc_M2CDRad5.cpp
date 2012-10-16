// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_NoDist__PProjInc_M2CDRad5.h"


cEqAppui_NoDist__PProjInc_M2CDRad5::cEqAppui_NoDist__PProjInc_M2CDRad5():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,10));
   AddIntRef (cIncIntervale("Orient",10,16));
   AddIntRef (cIncIntervale("Tmp_PTer",16,19));
   Close(false);
}



void cEqAppui_NoDist__PProjInc_M2CDRad5::ComputeVal()
{
   double tmp0_ = mCompCoord[10];
   double tmp1_ = mCompCoord[11];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[16];
   double tmp4_ = mCompCoord[17];
   double tmp5_ = mCompCoord[18];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[12];
   double tmp10_ = mLocProjI_x*tmp3_;
   double tmp11_ = mLocProjP0_x+tmp10_;
   double tmp12_ = mLocProjJ_x*tmp4_;
   double tmp13_ = tmp11_+tmp12_;
   double tmp14_ = mLocProjK_x/tmp5_;
   double tmp15_ = tmp13_+tmp14_;
   double tmp16_ = mCompCoord[13];
   double tmp17_ = (tmp15_)-tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y*tmp3_;
   double tmp23_ = mLocProjP0_y+tmp22_;
   double tmp24_ = mLocProjJ_y*tmp4_;
   double tmp25_ = tmp23_+tmp24_;
   double tmp26_ = mLocProjK_y/tmp5_;
   double tmp27_ = tmp25_+tmp26_;
   double tmp28_ = mCompCoord[14];
   double tmp29_ = (tmp27_)-tmp28_;
   double tmp30_ = mLocProjI_z*tmp3_;
   double tmp31_ = mLocProjP0_z+tmp30_;
   double tmp32_ = mLocProjJ_z*tmp4_;
   double tmp33_ = tmp31_+tmp32_;
   double tmp34_ = mLocProjK_z/tmp5_;
   double tmp35_ = tmp33_+tmp34_;
   double tmp36_ = mCompCoord[15];
   double tmp37_ = (tmp35_)-tmp36_;
   double tmp38_ = -(tmp6_);
   double tmp39_ = tmp7_*tmp20_;
   double tmp40_ = tmp6_*tmp20_;
   double tmp41_ = tmp38_*tmp19_;
   double tmp42_ = tmp39_*tmp21_;
   double tmp43_ = tmp41_+tmp42_;
   double tmp44_ = (tmp43_)*(tmp17_);
   double tmp45_ = tmp7_*tmp19_;
   double tmp46_ = tmp40_*tmp21_;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = (tmp47_)*(tmp29_);
   double tmp49_ = tmp44_+tmp48_;
   double tmp50_ = tmp2_*tmp21_;
   double tmp51_ = tmp50_*(tmp37_);
   double tmp52_ = tmp49_+tmp51_;
   double tmp53_ = tmp7_*tmp2_;
   double tmp54_ = tmp53_*(tmp17_);
   double tmp55_ = tmp6_*tmp2_;
   double tmp56_ = tmp55_*(tmp29_);
   double tmp57_ = tmp54_+tmp56_;
   double tmp58_ = tmp8_*(tmp37_);
   double tmp59_ = tmp57_+tmp58_;
   double tmp60_ = (tmp59_)/(tmp52_);
   double tmp61_ = tmp38_*tmp21_;
   double tmp62_ = tmp39_*tmp18_;
   double tmp63_ = tmp61_+tmp62_;
   double tmp64_ = (tmp63_)*(tmp17_);
   double tmp65_ = tmp7_*tmp21_;
   double tmp66_ = tmp40_*tmp18_;
   double tmp67_ = tmp65_+tmp66_;
   double tmp68_ = (tmp67_)*(tmp29_);
   double tmp69_ = tmp64_+tmp68_;
   double tmp70_ = tmp2_*tmp18_;
   double tmp71_ = tmp70_*(tmp37_);
   double tmp72_ = tmp69_+tmp71_;
   double tmp73_ = (tmp72_)/(tmp52_);

  mVal[0] = (mLocNDP0_x+mLocNDdx_x*(tmp60_)+mLocNDdy_x*(tmp73_))-mLocXIm;

  mVal[1] = (mLocNDP0_y+mLocNDdx_y*(tmp60_)+mLocNDdy_y*(tmp73_))-mLocYIm;

}


void cEqAppui_NoDist__PProjInc_M2CDRad5::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[10];
   double tmp1_ = mCompCoord[11];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[16];
   double tmp4_ = mCompCoord[17];
   double tmp5_ = mCompCoord[18];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[12];
   double tmp10_ = mLocProjI_x*tmp3_;
   double tmp11_ = mLocProjP0_x+tmp10_;
   double tmp12_ = mLocProjJ_x*tmp4_;
   double tmp13_ = tmp11_+tmp12_;
   double tmp14_ = mLocProjK_x/tmp5_;
   double tmp15_ = tmp13_+tmp14_;
   double tmp16_ = mCompCoord[13];
   double tmp17_ = (tmp15_)-tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y*tmp3_;
   double tmp23_ = mLocProjP0_y+tmp22_;
   double tmp24_ = mLocProjJ_y*tmp4_;
   double tmp25_ = tmp23_+tmp24_;
   double tmp26_ = mLocProjK_y/tmp5_;
   double tmp27_ = tmp25_+tmp26_;
   double tmp28_ = mCompCoord[14];
   double tmp29_ = (tmp27_)-tmp28_;
   double tmp30_ = mLocProjI_z*tmp3_;
   double tmp31_ = mLocProjP0_z+tmp30_;
   double tmp32_ = mLocProjJ_z*tmp4_;
   double tmp33_ = tmp31_+tmp32_;
   double tmp34_ = mLocProjK_z/tmp5_;
   double tmp35_ = tmp33_+tmp34_;
   double tmp36_ = mCompCoord[15];
   double tmp37_ = (tmp35_)-tmp36_;
   double tmp38_ = -(tmp6_);
   double tmp39_ = tmp7_*tmp20_;
   double tmp40_ = tmp6_*tmp20_;
   double tmp41_ = tmp38_*tmp19_;
   double tmp42_ = tmp39_*tmp21_;
   double tmp43_ = tmp41_+tmp42_;
   double tmp44_ = (tmp43_)*(tmp17_);
   double tmp45_ = tmp7_*tmp19_;
   double tmp46_ = tmp40_*tmp21_;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = (tmp47_)*(tmp29_);
   double tmp49_ = tmp44_+tmp48_;
   double tmp50_ = tmp2_*tmp21_;
   double tmp51_ = tmp50_*(tmp37_);
   double tmp52_ = tmp49_+tmp51_;
   double tmp53_ = tmp7_*tmp2_;
   double tmp54_ = tmp53_*(tmp17_);
   double tmp55_ = tmp6_*tmp2_;
   double tmp56_ = tmp55_*(tmp29_);
   double tmp57_ = tmp54_+tmp56_;
   double tmp58_ = tmp8_*(tmp37_);
   double tmp59_ = tmp57_+tmp58_;
   double tmp60_ = -(1);
   double tmp61_ = tmp60_*tmp6_;
   double tmp62_ = -(tmp7_);
   double tmp63_ = tmp61_*tmp20_;
   double tmp64_ = tmp39_*tmp18_;
   double tmp65_ = tmp38_*tmp21_;
   double tmp66_ = tmp65_+tmp64_;
   double tmp67_ = (tmp66_)*(tmp17_);
   double tmp68_ = tmp7_*tmp21_;
   double tmp69_ = tmp40_*tmp18_;
   double tmp70_ = tmp68_+tmp69_;
   double tmp71_ = (tmp70_)*(tmp29_);
   double tmp72_ = tmp67_+tmp71_;
   double tmp73_ = tmp2_*tmp18_;
   double tmp74_ = tmp73_*(tmp37_);
   double tmp75_ = tmp72_+tmp74_;
   double tmp76_ = tmp62_*tmp19_;
   double tmp77_ = tmp63_*tmp21_;
   double tmp78_ = tmp76_+tmp77_;
   double tmp79_ = (tmp78_)*(tmp17_);
   double tmp80_ = tmp61_*tmp19_;
   double tmp81_ = tmp80_+tmp42_;
   double tmp82_ = (tmp81_)*(tmp29_);
   double tmp83_ = tmp79_+tmp82_;
   double tmp84_ = ElSquare(tmp52_);
   double tmp85_ = tmp60_*tmp8_;
   double tmp86_ = -(tmp2_);
   double tmp87_ = tmp86_*tmp7_;
   double tmp88_ = tmp86_*tmp6_;
   double tmp89_ = tmp87_*tmp21_;
   double tmp90_ = tmp89_*(tmp17_);
   double tmp91_ = tmp88_*tmp21_;
   double tmp92_ = tmp91_*(tmp29_);
   double tmp93_ = tmp90_+tmp92_;
   double tmp94_ = tmp85_*tmp21_;
   double tmp95_ = tmp94_*(tmp37_);
   double tmp96_ = tmp93_+tmp95_;
   double tmp97_ = -(tmp21_);
   double tmp98_ = tmp60_*tmp18_;
   double tmp99_ = tmp97_*tmp38_;
   double tmp100_ = tmp98_*tmp39_;
   double tmp101_ = tmp99_+tmp100_;
   double tmp102_ = (tmp101_)*(tmp17_);
   double tmp103_ = tmp97_*tmp7_;
   double tmp104_ = tmp98_*tmp40_;
   double tmp105_ = tmp103_+tmp104_;
   double tmp106_ = (tmp105_)*(tmp29_);
   double tmp107_ = tmp102_+tmp106_;
   double tmp108_ = tmp98_*tmp2_;
   double tmp109_ = tmp108_*(tmp37_);
   double tmp110_ = tmp107_+tmp109_;
   double tmp111_ = tmp60_*(tmp43_);
   double tmp112_ = tmp60_*(tmp47_);
   double tmp113_ = tmp60_*tmp50_;
   double tmp114_ = mLocProjI_x*(tmp43_);
   double tmp115_ = mLocProjI_y*(tmp47_);
   double tmp116_ = tmp114_+tmp115_;
   double tmp117_ = mLocProjI_z*tmp50_;
   double tmp118_ = tmp116_+tmp117_;
   double tmp119_ = mLocProjJ_x*(tmp43_);
   double tmp120_ = mLocProjJ_y*(tmp47_);
   double tmp121_ = tmp119_+tmp120_;
   double tmp122_ = mLocProjJ_z*tmp50_;
   double tmp123_ = tmp121_+tmp122_;
   double tmp124_ = ElSquare(tmp5_);
   double tmp125_ = -(mLocProjK_x);
   double tmp126_ = tmp125_/tmp124_;
   double tmp127_ = -(mLocProjK_y);
   double tmp128_ = tmp127_/tmp124_;
   double tmp129_ = -(mLocProjK_z);
   double tmp130_ = tmp129_/tmp124_;
   double tmp131_ = (tmp126_)*(tmp43_);
   double tmp132_ = (tmp128_)*(tmp47_);
   double tmp133_ = tmp131_+tmp132_;
   double tmp134_ = (tmp130_)*tmp50_;
   double tmp135_ = tmp133_+tmp134_;
   double tmp136_ = (tmp59_)/(tmp52_);
   double tmp137_ = (tmp75_)/(tmp52_);
   double tmp138_ = tmp61_*tmp2_;
   double tmp139_ = tmp138_*(tmp17_);
   double tmp140_ = tmp53_*(tmp29_);
   double tmp141_ = tmp139_+tmp140_;
   double tmp142_ = (tmp141_)*(tmp52_);
   double tmp143_ = (tmp59_)*(tmp83_);
   double tmp144_ = tmp142_-tmp143_;
   double tmp145_ = (tmp144_)/tmp84_;
   double tmp146_ = tmp62_*tmp21_;
   double tmp147_ = tmp63_*tmp18_;
   double tmp148_ = tmp146_+tmp147_;
   double tmp149_ = (tmp148_)*(tmp17_);
   double tmp150_ = tmp61_*tmp21_;
   double tmp151_ = tmp150_+tmp64_;
   double tmp152_ = (tmp151_)*(tmp29_);
   double tmp153_ = tmp149_+tmp152_;
   double tmp154_ = (tmp153_)*(tmp52_);
   double tmp155_ = (tmp75_)*(tmp83_);
   double tmp156_ = tmp154_-tmp155_;
   double tmp157_ = (tmp156_)/tmp84_;
   double tmp158_ = tmp85_*tmp7_;
   double tmp159_ = tmp158_*(tmp17_);
   double tmp160_ = tmp85_*tmp6_;
   double tmp161_ = tmp160_*(tmp29_);
   double tmp162_ = tmp159_+tmp161_;
   double tmp163_ = tmp2_*(tmp37_);
   double tmp164_ = tmp162_+tmp163_;
   double tmp165_ = (tmp164_)*(tmp52_);
   double tmp166_ = (tmp59_)*(tmp96_);
   double tmp167_ = tmp165_-tmp166_;
   double tmp168_ = (tmp167_)/tmp84_;
   double tmp169_ = tmp87_*tmp18_;
   double tmp170_ = tmp169_*(tmp17_);
   double tmp171_ = tmp88_*tmp18_;
   double tmp172_ = tmp171_*(tmp29_);
   double tmp173_ = tmp170_+tmp172_;
   double tmp174_ = tmp85_*tmp18_;
   double tmp175_ = tmp174_*(tmp37_);
   double tmp176_ = tmp173_+tmp175_;
   double tmp177_ = (tmp176_)*(tmp52_);
   double tmp178_ = (tmp75_)*(tmp96_);
   double tmp179_ = tmp177_-tmp178_;
   double tmp180_ = (tmp179_)/tmp84_;
   double tmp181_ = (tmp59_)*(tmp110_);
   double tmp182_ = -(tmp181_);
   double tmp183_ = tmp182_/tmp84_;
   double tmp184_ = tmp98_*tmp38_;
   double tmp185_ = tmp21_*tmp39_;
   double tmp186_ = tmp184_+tmp185_;
   double tmp187_ = (tmp186_)*(tmp17_);
   double tmp188_ = tmp98_*tmp7_;
   double tmp189_ = tmp21_*tmp40_;
   double tmp190_ = tmp188_+tmp189_;
   double tmp191_ = (tmp190_)*(tmp29_);
   double tmp192_ = tmp187_+tmp191_;
   double tmp193_ = tmp21_*tmp2_;
   double tmp194_ = tmp193_*(tmp37_);
   double tmp195_ = tmp192_+tmp194_;
   double tmp196_ = (tmp195_)*(tmp52_);
   double tmp197_ = (tmp75_)*(tmp110_);
   double tmp198_ = tmp196_-tmp197_;
   double tmp199_ = (tmp198_)/tmp84_;
   double tmp200_ = tmp60_*tmp53_;
   double tmp201_ = tmp200_*(tmp52_);
   double tmp202_ = (tmp59_)*tmp111_;
   double tmp203_ = tmp201_-tmp202_;
   double tmp204_ = (tmp203_)/tmp84_;
   double tmp205_ = tmp60_*(tmp66_);
   double tmp206_ = tmp205_*(tmp52_);
   double tmp207_ = (tmp75_)*tmp111_;
   double tmp208_ = tmp206_-tmp207_;
   double tmp209_ = (tmp208_)/tmp84_;
   double tmp210_ = tmp60_*tmp55_;
   double tmp211_ = tmp210_*(tmp52_);
   double tmp212_ = (tmp59_)*tmp112_;
   double tmp213_ = tmp211_-tmp212_;
   double tmp214_ = (tmp213_)/tmp84_;
   double tmp215_ = tmp60_*(tmp70_);
   double tmp216_ = tmp215_*(tmp52_);
   double tmp217_ = (tmp75_)*tmp112_;
   double tmp218_ = tmp216_-tmp217_;
   double tmp219_ = (tmp218_)/tmp84_;
   double tmp220_ = tmp85_*(tmp52_);
   double tmp221_ = (tmp59_)*tmp113_;
   double tmp222_ = tmp220_-tmp221_;
   double tmp223_ = (tmp222_)/tmp84_;
   double tmp224_ = tmp60_*tmp73_;
   double tmp225_ = tmp224_*(tmp52_);
   double tmp226_ = (tmp75_)*tmp113_;
   double tmp227_ = tmp225_-tmp226_;
   double tmp228_ = (tmp227_)/tmp84_;
   double tmp229_ = mLocProjI_x*tmp53_;
   double tmp230_ = mLocProjI_y*tmp55_;
   double tmp231_ = tmp229_+tmp230_;
   double tmp232_ = mLocProjI_z*tmp8_;
   double tmp233_ = tmp231_+tmp232_;
   double tmp234_ = (tmp233_)*(tmp52_);
   double tmp235_ = (tmp59_)*(tmp118_);
   double tmp236_ = tmp234_-tmp235_;
   double tmp237_ = (tmp236_)/tmp84_;
   double tmp238_ = mLocProjI_x*(tmp66_);
   double tmp239_ = mLocProjI_y*(tmp70_);
   double tmp240_ = tmp238_+tmp239_;
   double tmp241_ = mLocProjI_z*tmp73_;
   double tmp242_ = tmp240_+tmp241_;
   double tmp243_ = (tmp242_)*(tmp52_);
   double tmp244_ = (tmp75_)*(tmp118_);
   double tmp245_ = tmp243_-tmp244_;
   double tmp246_ = (tmp245_)/tmp84_;
   double tmp247_ = mLocProjJ_x*tmp53_;
   double tmp248_ = mLocProjJ_y*tmp55_;
   double tmp249_ = tmp247_+tmp248_;
   double tmp250_ = mLocProjJ_z*tmp8_;
   double tmp251_ = tmp249_+tmp250_;
   double tmp252_ = (tmp251_)*(tmp52_);
   double tmp253_ = (tmp59_)*(tmp123_);
   double tmp254_ = tmp252_-tmp253_;
   double tmp255_ = (tmp254_)/tmp84_;
   double tmp256_ = mLocProjJ_x*(tmp66_);
   double tmp257_ = mLocProjJ_y*(tmp70_);
   double tmp258_ = tmp256_+tmp257_;
   double tmp259_ = mLocProjJ_z*tmp73_;
   double tmp260_ = tmp258_+tmp259_;
   double tmp261_ = (tmp260_)*(tmp52_);
   double tmp262_ = (tmp75_)*(tmp123_);
   double tmp263_ = tmp261_-tmp262_;
   double tmp264_ = (tmp263_)/tmp84_;
   double tmp265_ = (tmp126_)*tmp53_;
   double tmp266_ = (tmp128_)*tmp55_;
   double tmp267_ = tmp265_+tmp266_;
   double tmp268_ = (tmp130_)*tmp8_;
   double tmp269_ = tmp267_+tmp268_;
   double tmp270_ = (tmp269_)*(tmp52_);
   double tmp271_ = (tmp59_)*(tmp135_);
   double tmp272_ = tmp270_-tmp271_;
   double tmp273_ = (tmp272_)/tmp84_;
   double tmp274_ = (tmp126_)*(tmp66_);
   double tmp275_ = (tmp128_)*(tmp70_);
   double tmp276_ = tmp274_+tmp275_;
   double tmp277_ = (tmp130_)*tmp73_;
   double tmp278_ = tmp276_+tmp277_;
   double tmp279_ = (tmp278_)*(tmp52_);
   double tmp280_ = (tmp75_)*(tmp135_);
   double tmp281_ = tmp279_-tmp280_;
   double tmp282_ = (tmp281_)/tmp84_;

  mVal[0] = (mLocNDP0_x+mLocNDdx_x*(tmp136_)+mLocNDdy_x*(tmp137_))-mLocXIm;

  mCompDer[0][0] = 0;
  mCompDer[0][1] = 0;
  mCompDer[0][2] = 0;
  mCompDer[0][3] = 0;
  mCompDer[0][4] = 0;
  mCompDer[0][5] = 0;
  mCompDer[0][6] = 0;
  mCompDer[0][7] = 0;
  mCompDer[0][8] = 0;
  mCompDer[0][9] = 0;
  mCompDer[0][10] = (tmp145_)*mLocNDdx_x+(tmp157_)*mLocNDdy_x;
  mCompDer[0][11] = (tmp168_)*mLocNDdx_x+(tmp180_)*mLocNDdy_x;
  mCompDer[0][12] = (tmp183_)*mLocNDdx_x+(tmp199_)*mLocNDdy_x;
  mCompDer[0][13] = (tmp204_)*mLocNDdx_x+(tmp209_)*mLocNDdy_x;
  mCompDer[0][14] = (tmp214_)*mLocNDdx_x+(tmp219_)*mLocNDdy_x;
  mCompDer[0][15] = (tmp223_)*mLocNDdx_x+(tmp228_)*mLocNDdy_x;
  mCompDer[0][16] = (tmp237_)*mLocNDdx_x+(tmp246_)*mLocNDdy_x;
  mCompDer[0][17] = (tmp255_)*mLocNDdx_x+(tmp264_)*mLocNDdy_x;
  mCompDer[0][18] = (tmp273_)*mLocNDdx_x+(tmp282_)*mLocNDdy_x;
  mVal[1] = (mLocNDP0_y+mLocNDdx_y*(tmp136_)+mLocNDdy_y*(tmp137_))-mLocYIm;

  mCompDer[1][0] = 0;
  mCompDer[1][1] = 0;
  mCompDer[1][2] = 0;
  mCompDer[1][3] = 0;
  mCompDer[1][4] = 0;
  mCompDer[1][5] = 0;
  mCompDer[1][6] = 0;
  mCompDer[1][7] = 0;
  mCompDer[1][8] = 0;
  mCompDer[1][9] = 0;
  mCompDer[1][10] = (tmp145_)*mLocNDdx_y+(tmp157_)*mLocNDdy_y;
  mCompDer[1][11] = (tmp168_)*mLocNDdx_y+(tmp180_)*mLocNDdy_y;
  mCompDer[1][12] = (tmp183_)*mLocNDdx_y+(tmp199_)*mLocNDdy_y;
  mCompDer[1][13] = (tmp204_)*mLocNDdx_y+(tmp209_)*mLocNDdy_y;
  mCompDer[1][14] = (tmp214_)*mLocNDdx_y+(tmp219_)*mLocNDdy_y;
  mCompDer[1][15] = (tmp223_)*mLocNDdx_y+(tmp228_)*mLocNDdy_y;
  mCompDer[1][16] = (tmp237_)*mLocNDdx_y+(tmp246_)*mLocNDdy_y;
  mCompDer[1][17] = (tmp255_)*mLocNDdx_y+(tmp264_)*mLocNDdy_y;
  mCompDer[1][18] = (tmp273_)*mLocNDdx_y+(tmp282_)*mLocNDdy_y;
}


void cEqAppui_NoDist__PProjInc_M2CDRad5::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_NoDist__PProjInc_M2CDRad5 Has no Der Sec");
}

void cEqAppui_NoDist__PProjInc_M2CDRad5::SetNDP0_x(double aVal){ mLocNDP0_x = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetNDP0_y(double aVal){ mLocNDP0_y = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetNDdx_x(double aVal){ mLocNDdx_x = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetNDdx_y(double aVal){ mLocNDdx_y = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetNDdy_x(double aVal){ mLocNDdy_x = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetNDdy_y(double aVal){ mLocNDdy_y = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjI_x(double aVal){ mLocProjI_x = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjI_y(double aVal){ mLocProjI_y = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjI_z(double aVal){ mLocProjI_z = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjJ_x(double aVal){ mLocProjJ_x = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjJ_y(double aVal){ mLocProjJ_y = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjJ_z(double aVal){ mLocProjJ_z = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjK_x(double aVal){ mLocProjK_x = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjK_y(double aVal){ mLocProjK_y = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjK_z(double aVal){ mLocProjK_z = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjP0_x(double aVal){ mLocProjP0_x = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjP0_y(double aVal){ mLocProjP0_y = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetProjP0_z(double aVal){ mLocProjP0_z = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_NoDist__PProjInc_M2CDRad5::SetYIm(double aVal){ mLocYIm = aVal;}



double * cEqAppui_NoDist__PProjInc_M2CDRad5::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "NDP0_x") return & mLocNDP0_x;
   if (aName == "NDP0_y") return & mLocNDP0_y;
   if (aName == "NDdx_x") return & mLocNDdx_x;
   if (aName == "NDdx_y") return & mLocNDdx_y;
   if (aName == "NDdy_x") return & mLocNDdy_x;
   if (aName == "NDdy_y") return & mLocNDdy_y;
   if (aName == "ProjI_x") return & mLocProjI_x;
   if (aName == "ProjI_y") return & mLocProjI_y;
   if (aName == "ProjI_z") return & mLocProjI_z;
   if (aName == "ProjJ_x") return & mLocProjJ_x;
   if (aName == "ProjJ_y") return & mLocProjJ_y;
   if (aName == "ProjJ_z") return & mLocProjJ_z;
   if (aName == "ProjK_x") return & mLocProjK_x;
   if (aName == "ProjK_y") return & mLocProjK_y;
   if (aName == "ProjK_z") return & mLocProjK_z;
   if (aName == "ProjP0_x") return & mLocProjP0_x;
   if (aName == "ProjP0_y") return & mLocProjP0_y;
   if (aName == "ProjP0_z") return & mLocProjP0_z;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "YIm") return & mLocYIm;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_NoDist__PProjInc_M2CDRad5::mTheAuto("cEqAppui_NoDist__PProjInc_M2CDRad5",cEqAppui_NoDist__PProjInc_M2CDRad5::Alloc);


cElCompiledFonc *  cEqAppui_NoDist__PProjInc_M2CDRad5::Alloc()
{  return new cEqAppui_NoDist__PProjInc_M2CDRad5();
}


