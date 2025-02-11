//#define aNbType 2
//std::string  Type[aNbType] = {"BruteForce","Guided"};


/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/

#include "TiePHistorical.h"



/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
aooter-MicMac-eLiSe-25/06/2007*/

std::string GetFileName(std::string strIn)
{
    std::string strOut = strIn;

    std::size_t found = strIn.find("/");
    if (found!=std::string::npos)
        strOut = strIn.substr(found+1, strIn.length());

    return strOut;
}

std::string GetFolderName(std::string strIn)
{
    std::string strOut = "";

    std::size_t found = strIn.find("/");
    if (found!=std::string::npos) //std::string::npos means postion that does not exist
        strOut = strIn.substr(0, found);

    return strOut;
}

void WriteXml(std::string aImg1, std::string aImg2, std::string aSubPatchXml, std::vector<std::string> vPatchesL, std::vector<std::string> vPatchesR, std::vector<cElHomographie> vHomoL, std::vector<cElHomographie> vHomoR, bool bPrint)
{
    //cout<<aSubPatchXml<<endl;
    cSetOfPatches aDAFout;

    cMes1Im aIms1;
    cMes1Im aIms2;

    aIms1.NameIm() = GetFileName(aImg1);
    aIms2.NameIm() = GetFileName(aImg2);

    //cout<<aIms1.NameIm()<<endl;

    int nPatchNumL = vPatchesL.size();
    int nPatchNumR = vPatchesR.size();
    for(int i=0; i < nPatchNumL; i++)
    {
        //cout<<i<<"/"<<nPatchNum<<endl;
        cOnePatch1I patch1;
        patch1.NamePatch() = vPatchesL[i];
        patch1.PatchH() = vHomoL[i].ToXml();
        aIms1.OnePatch1I().push_back(patch1);

        if(bPrint)
        {
            printf("%d, %s: \n", i, vPatchesL[i].c_str());
            vHomoL[i].Show();
        }
    }

    for(int i=0; i < nPatchNumR; i++)
    {
        cOnePatch1I patch2;
        patch2.NamePatch() = vPatchesR[i];
        patch2.PatchH() = vHomoR[i].ToXml();
        aIms2.OnePatch1I().push_back(patch2);

        if(bPrint)
        {
            printf("%d, %s: \n", i, vPatchesR[i].c_str());
            vHomoR[i].Show();
        }
    }

    aDAFout.Mes1Im().push_back(aIms1);
    aDAFout.Mes1Im().push_back(aIms2);

    MakeFileXML(aDAFout, aSubPatchXml);
}

//simply clip images to get master patches (m patches), and resample images to get secondary patches (m patches). The number of pairs to be matched will be m.
//mainly used for precise matching
void GetPatchPair(std::string aOutDir, std::string aOutImg1, std::string aOutImg2, std::string aImg1, std::string aImg2, std::string aOri1, std::string aOri2, cInterfChantierNameManipulateur * aICNM, Pt2dr aPatchSz, Pt2dr aBufferSz, std::string aImgPair, std::string aDir, std::string aSubPatchXml, cTransform3DHelmert aTrans3DH, std::string aDSMFileL, std::string aDSMDirL, double aThres, double dDyn, bool bPrint=false, std::string aPrefix="")
{
    std::string aOriginImg1 = aImg1;

    aImg1 = aPrefix + aImg1;
    aImg2 = aPrefix + aImg2;
    aOutImg1 = aPrefix + aOutImg1;
    aOutImg2 = aPrefix + aOutImg2;

    if (ELISE_fp::exist_file(aDir+aImg1) == false || ELISE_fp::exist_file(aDir+aImg2) == false)
    {
        cout<<aDir+aImg1<<" or "<<aDir+aImg2<<" didn't exist, hence skipped"<<endl;
        return;
    }

    Tiff_Im aRGBIm1((aDir+aImg1).c_str());
    Pt2di ImgSzL = aRGBIm1.sz();
    Tiff_Im aRGBIm2((aDir+aImg2).c_str());
    Pt2di ImgSzR = aRGBIm2.sz();

    GenIm::type_el aTypeIm1 = aRGBIm1.type_el();
    GenIm::type_el aTypeIm2 = aRGBIm2.type_el();

    cout<<"type of "<<aImg1<<": "<<aTypeIm1<<endl;
    cout<<"type of "<<aImg2<<": "<<aTypeIm2<<endl;

    std::string aImgRef1 = aImg1;
    std::string aImgRef2 = aImg2;
    bool bTo8Bits1 = false;
    bool bTo8Bits2 = false;

    if(aTypeIm1 == 2)
    {
        aImgRef1 = aImg1 + "_to8Bits.tif";
        std::string aComto8Bits = MMBinFile(MM3DStr) + "to8Bits " + aImg1 + " Out=" + aImgRef1 + " Dyn=" + ToString(dDyn);
        cout<<aComto8Bits<<endl;
        System(aComto8Bits);
        bTo8Bits1 = true;
        //cout<<aImg1<<" transformed to "<<aImgRef1<<endl;
    }
    if(aTypeIm2 == 2)
    {
        aImgRef2 = aImg2 + "_to8Bits.tif";
        std::string aComto8Bits = MMBinFile(MM3DStr) + "to8Bits " + aImg2 + " Out=" + aImgRef2 + " Dyn=" + ToString(dDyn);
        cout<<aComto8Bits<<endl;
        System(aComto8Bits);
        bTo8Bits2 = true;
        //cout<<aImg2<<" transformed to "<<aImgRef2<<endl;
    }

    Pt2dr CoreaPatchSz;
    CoreaPatchSz.x = aPatchSz.x - aBufferSz.x*2;
    CoreaPatchSz.y = aPatchSz.y - aBufferSz.y*2;

    Pt2di PatchNum;
    //"-2*aBufferSz.x" to avoid left-top patch having margin, and to avoid unnecessary right-lower patches
    PatchNum.x = ceil((ImgSzL.x-2*aBufferSz.x)*1.0/CoreaPatchSz.x);
    PatchNum.y = ceil((ImgSzL.y-2*aBufferSz.y)*1.0/CoreaPatchSz.y);

    int aType = eTIGB_Unknown;
    std::string aIm1OriFile = aICNM->StdNameCamGenOfNames(aOri1, aImg1);
    std::string aIm2OriFile = aICNM->StdNameCamGenOfNames(aOri2, aImg2);
    cBasicGeomCap3D * aCamL = cBasicGeomCap3D::StdGetFromFile(aIm1OriFile,aType);
    cBasicGeomCap3D * aCamR = cBasicGeomCap3D::StdGetFromFile(aIm2OriFile,aType);
    double dZL = aCamL->GetAltiSol();

    if(bPrint)
    {
        //printf("GetProfondeur: %.2lf, GetAltiSol: %.2lf\n", prof_d, altiSol);
        printf("GetAltiSol: %.2lf\n", dZL);
    }

    Pt2dr aPCornerPatch[4];
    Pt2dr origin = Pt2dr(0, 0);
    aPCornerPatch[0] = origin;
    aPCornerPatch[1] = Pt2dr(origin.x+aPatchSz.x, origin.y);
    aPCornerPatch[2] = Pt2dr(origin.x+aPatchSz.x, origin.y+aPatchSz.y);
    aPCornerPatch[3] = Pt2dr(origin.x, origin.y+aPatchSz.y);

    //save the name and homography of patches, for saving the xml file latter
    std::vector<std::string> vPatchesL, vPatchesR;
    std::vector<cElHomographie> vHomoL, vHomoR;

    std::vector<string> vaImgPair;
    int m, n;
    std::list<std::string> aLComClip, aLComResample;
    std::string aComBaseClip = MMBinFile(MM3DStr) + "ClipIm " + aImgRef1 + " ";
    std::string aComBaseResample = MMBinFile(MM3DStr) + "TestLib OneReechFromAscii ";
    std::string aClipSz = " ["+std::to_string(int(aPatchSz.x))+","+std::to_string(int(aPatchSz.y))+"] ";

    //Because TestLib OneReechFromAscii output the result in the same directory of aImg2, so we need to move the result txt and tif file into aOutDir
    std::list<std::string> aComMv;

    cout<<"Patch number of "<<aOutImg1<<": "<<PatchNum.x<<"*"<<PatchNum.y<<"="<<PatchNum.x*PatchNum.y<<endl;

    cGet3Dcoor a3DCoorL(aIm1OriFile);
    cDSMInfo aDSMInfoL = a3DCoorL.SetDSMInfo(aDSMFileL, aDSMDirL);

    for(m=0; m<PatchNum.x; m++)
    {
        for(n=0; n<PatchNum.y; n++)
        {
            std::string aSubImg1 = StdPrefix(aOutImg1) + "_" + std::to_string(m) + "_" + std::to_string(n) + "." + StdPostfix(aOutImg1);

            //to avoid left-top patch having margin, and to avoid unnecessary right-lower patches
            origin.x = m*CoreaPatchSz.x;
            origin.y = n*CoreaPatchSz.y;

            // 1. use ClipIm command to clip master image into patches
            std::string aComClipMasterImg = aComBaseClip + " ["+std::to_string(int(origin.x))+","+std::to_string(int(origin.y))+"] " + aClipSz + " Out="+aOutDir+"/"+aSubImg1;
            cout<<aComClipMasterImg<<endl;
            aLComClip.push_back(aComClipMasterImg);

            cElComposHomographie aFstHX(1, 0, origin.x);
            cElComposHomographie aFstHY(0, 1, origin.y);
            cElComposHomographie aFstHZ(0, 0,        1);
            cElHomographie  aFstH =  cElHomographie(aFstHX,aFstHY,aFstHZ);

            // 2. use "TestLib OneReechFromAscii" command to clip secondary image into patches by reprojecting the master patches to the secondary image
            if(true)
            {
                double dScaleL = 1;
                double dScaleR = 1;

                Pt2dr aPCornerL[4];
                aPCornerL[0] = origin;
                aPCornerL[1] = Pt2dr(origin.x+aPatchSz.x, origin.y);
                aPCornerL[2] = Pt2dr(origin.x+aPatchSz.x, origin.y+aPatchSz.y);
                aPCornerL[3] = Pt2dr(origin.x, origin.y+aPatchSz.y);

                Pt2dr aPCornerR[4];
                for(int i=0; i<4; i++)
                {
                    Pt2dr aP1 = aPCornerL[i];
                    aP1.x = aP1.x*dScaleL;
                    aP1.y = aP1.y*dScaleL;

                    Pt3dr aPTer1;
                    /*if(aDSMDirL.length() > 0)
                    {*/
                        //TIm2D<float,double> aTImProfPxL = a3DCoorL.SetDSMInfo(aDSMFileL, aDSMDirL);
                        bool bValidL;
                        aPTer1 = a3DCoorL.Get3Dcoor(aP1, aDSMInfoL, bValidL, bPrint, aThres);//, a3DCoorL.GetGSD());
                    /*}
                    else
                    {
                        //aPTer1 = aCamL->ImEtProf2Terrain(aP1, prof_d);
                        aPTer1 = aCamL->ImEtZ2Terrain(aP1, dZL);
                    }*/
                    //Pt2dr aP2 = aCamL->Ter2Capteur(aPTer1);
                    //printf("%.2lf\t%.2lf\t%.2lf\t%.2lf\n", aP1.x, aP1.y, aP2.x, aP2.y);

                    aPTer1 = aTrans3DH.Transform3Dcoor(aPTer1);

                    //aPCornerR[i] = aCamR->R3toF2(aPTer1);
                    aPCornerR[i] = aCamR->Ter2Capteur(aPTer1);
                    aPCornerR[i].x = aPCornerR[i].x/dScaleL/dScaleR;
                    aPCornerR[i].y = aPCornerR[i].y/dScaleL/dScaleR;

                    if(bPrint)
                    {
                        printf("%dth: CornerL: [%.2lf\t%.2lf], ImEtProf2Terrain: [%.2lf\t%.2lf\t%.2lf], CornerR: [%.2lf\t%.2lf]\n", i, aPCornerL[i].x, aPCornerL[i].y, aPTer1.x, aPTer1.y, aPTer1.z, aPCornerR[i].x, aPCornerR[i].y);
                        //printf("ImEtZ2Terrain: [%.2lf\t%.2lf\t%.2lf]\n", Pt_H_sol.x, Pt_H_sol.y, Pt_H_sol.z);
                    }
                }

                std::string aNameSave = StdPrefix(aOutImg2) + "_" + StdPrefix(aOriginImg1) + "_" + std::to_string(m) + "_" + std::to_string(n);
                std::string aSubImg2 = aNameSave + "." + StdPostfix(aOutImg2);
                aNameSave += ".txt";
                //cout<<aNameSave<<endl;
                if(FallInBox(aPCornerR, Pt2dr(0,0), ImgSzR) == true)
                {
                    vaImgPair.push_back(aSubImg1 + " " + aSubImg2);
                    //cout<<"fall in box"<<endl;
                    FILE * fpOutput = fopen((aNameSave).c_str(), "w");
                    for(int i=0; i<4; i++)
                    {
                        fprintf(fpOutput, "%lf %lf %lf %lf\n", aPCornerPatch[i].x, aPCornerPatch[i].y, aPCornerR[i].x, aPCornerR[i].y);
                    }
                    fclose(fpOutput);

                    std::string aComResampleSndImg = aComBaseResample + aImgRef2  + " " + aNameSave + " Out="+aSubImg2 + " Show=true";
                    cout<<aComResampleSndImg<<endl;
                    aLComResample.push_back(aComResampleSndImg);

                    std::string aMvTxt = "mv "+aNameSave + " "+aOutDir+"/"+aNameSave;
                    std::string aMvTif = "mv "+aSubImg2 + " "+aOutDir+"/"+aSubImg2;
                    aComMv.push_back(aMvTxt);
                    aComMv.push_back(aMvTif);
                }
                else
                {
                    if(bPrint)
                        cout<<aNameSave<<" out of border, hence the current patch is not saved"<<endl;
                }

                    //Save the homography, this is copied from function "cAppliReechHomogr::cAppliReechHomogr(int argc,char ** argv)  :" in src/uti_phgrm/CPP_CreateEpip.cpp, where the patch is resampled
                    ElPackHomologue aPack;
                    //aPack = ElPackHomologue::FromFile(aNameSave);
                    for(int i=0; i<4; i++)
                    {
                        //aPack.Cple_Add(ElCplePtsHomologues(aPCornerPatch[i], aPCornerR[i]));
                        if(bPrint)
                            printf("aPCornerPatch[%d], aPCornerR[%d]: %.2lf\t%.2lf\t%.2lf\t%.2lf\n", i, i, aPCornerPatch[i].x, aPCornerPatch[i].y, aPCornerR[i].x, aPCornerR[i].y);
                    }
                    if(ELISE_fp::exist_file(aNameSave))
                        aPack = ElPackHomologue::FromFile(aNameSave);
                    else
                        for(int i=0; i<4; i++)
                            aPack.Cple_Add(ElCplePtsHomologues(aPCornerPatch[i], aPCornerR[i]));

                    double anEcart,aQuality;
                    bool Ok;
                    cElHomographie aSndH = cElHomographie::RobustInit(anEcart,&aQuality,aPack,Ok,50,80.0,2000);
                    std::cout << "Ecart " << anEcart << " ; Quality " << aQuality    << " \n";

                    vPatchesL.push_back(aSubImg1);
                    vHomoL.push_back(aFstH);
                    vPatchesR.push_back(aSubImg2);
                    vHomoR.push_back(aSndH);
                    if(bPrint){
                        aFstH.Show();
                        aSndH.Show();
                    }
            }
            //end
        }
    }

    //write SuperGlueInput.txt
    //std::string aDir = "/home/lulin/Documents/zll/TestLulinCodeInMicMac/SpGlue/new/";
    FILE * fpOutput = fopen((aOutDir+aImgPair).c_str(), "w");
    int nPairNum = vaImgPair.size();
    for(int i=0; i<nPairNum; i++)
    {
        fprintf(fpOutput, "%s", vaImgPair[i].c_str());
        if(i<nPairNum-1)
            fprintf(fpOutput, "\n");
    }
    fclose(fpOutput);

    WriteXml(aImg1, aImg2, aOutDir+aSubPatchXml, vPatchesL, vPatchesR, vHomoL, vHomoR, bPrint);

    cEl_GPAO::DoComInParal(aLComClip);
    cEl_GPAO::DoComInSerie(aLComResample);
    cEl_GPAO::DoComInParal(aComMv);

    if(bTo8Bits1 == true)
    {
        std::string aComRemove ="rm -r " + aImgRef1;
        System(aComRemove);
        cout<<aComRemove<<endl;
    }
    if(bTo8Bits2 == true)
    {
        std::string aComRemove ="rm -r " + aImgRef2;
        System(aComRemove);
        cout<<aComRemove<<endl;
    }
    /* if use cEl_GPAO::DoComInParal(aLComResample), something like this will happen:
    Error while file reading |
    FILE = ./Tmp-MM-Dir/14FRPCAB35x00014_01036.tif_Ch1.tif  pos = 20971528|
 reading 1 , got 0|------------------------------------------------------------
|   Sorry, the following FATAL ERROR happened
|
|    Error while file reading
|
------------------------------------------------------------
-------------------------------------------------------------
|       (Elise's)  LOCATION :
|
| Error was detected
|          at line : 1255
|          of file : /home/lulin/micmac/src/util/files.cpp
-------------------------------------------------------------
*/
}

Pt2dr ClipImg(std::string aOutImg1, std::string aImg1, Pt2di ImgSzL, Pt2dr aPatchSz, Pt2dr aBufferSz, Pt2dr origin, std::string aOutDir, std::list<std::string>& aLComClip, std::vector<std::string>& vPatchesL, std::vector<cElHomographie>& vHomoL)
{
    Pt2dr CoreaPatchSz;
    CoreaPatchSz.x = aPatchSz.x - aBufferSz.x*2;
    CoreaPatchSz.y = aPatchSz.y - aBufferSz.y*2;

    Pt2dr PatchNum;
    PatchNum.x = int(ImgSzL.x*1.0/CoreaPatchSz.x)+1;
    PatchNum.y = int(ImgSzL.y*1.0/CoreaPatchSz.y)+1;

    std::string aComBaseClip = MMBinFile(MM3DStr) + "ClipIm " + aImg1 + " ";
    std::string aClipSz = " ["+std::to_string(int(aPatchSz.x))+","+std::to_string(int(aPatchSz.y))+"] ";

    cout<<"Patch number of "<<aOutImg1<<": "<<PatchNum.x<<"*"<<PatchNum.y<<"="<<PatchNum.x*PatchNum.y<<endl;

    int m, n;
    for(m=0; m<PatchNum.x; m++)
    {
        for(n=0; n<PatchNum.y; n++)
        {
            std::string aSubImg1 = StdPrefix(aOutImg1) + "_" + std::to_string(m) + "_" + std::to_string(n) + "." + StdPostfix(aOutImg1);

            origin.x = m*CoreaPatchSz.x - aBufferSz.x;
            origin.y = n*CoreaPatchSz.y - aBufferSz.y;

            // 1. use ClipIm command to clip master image into patches
            std::string aComClipMasterImg = aComBaseClip + " ["+std::to_string(int(origin.x))+","+std::to_string(int(origin.y))+"] " + aClipSz + "Out="+aOutDir+"/"+aSubImg1;
            //cout<<aComClipMasterImg<<endl;
            aLComClip.push_back(aComClipMasterImg);

            cElComposHomographie aFstHX(1, 0, origin.x);
            cElComposHomographie aFstHY(0, 1, origin.y);
            cElComposHomographie aFstHZ(0, 0,        1);
            cElHomographie  aFstH =  cElHomographie(aFstHX,aFstHY,aFstHZ);

            vPatchesL.push_back(aSubImg1);
            vHomoL.push_back(aFstH);
        }
    }
    return PatchNum;
}

//simply clip images to get master patches (m patches) and secondary patches (n patches).  The number of pairs to be matched will be m*n.
//mainly used for rough co-registration
//aOriImg1 is the orginal master image, aImg1 could be the same as aOriImg1 (in this case aIm1_OriImg1 is unit matrix), or rotated image based on aOriImg1
void GetTilePair(std::string aOutDir, std::string aOriOutImg1, std::string aRotateOutImg1, std::string aOutImg2, std::string aImg1, std::string aImg2, Pt2dr aPatchSz, Pt2dr aBufferSz, std::string aImgPair, std::string aDir, std::string aSubPatchXml, std::string aOriImg1, cElHomographie aIm1_OriImg1, bool bPrint, double dDyn)
{
    //cout<<aDir<<endl;
    if (ELISE_fp::exist_file(aDir+aImg1) == false || ELISE_fp::exist_file(aDir+aImg2) == false)
    {
        cout<<aDir+aImg1<<" or "<<aDir+aImg2<<" didn't exist, hence skipped"<<endl;
        return;
    }

    std::string strCpImg;
    strCpImg = "cp "+aDir+aOriImg1+" "+aOutDir+aOriOutImg1;
    cout<<strCpImg<<endl;
    System(strCpImg);
    strCpImg = "cp "+aDir+aImg2+" "+aOutDir+aOutImg2;
    cout<<strCpImg<<endl;
    System(strCpImg);

    Tiff_Im aDSMIm1((aDir+aImg1).c_str());
    Pt2di ImgSzL = aDSMIm1.sz();
    Tiff_Im aDSMIm2((aDir+aImg2).c_str());
    Pt2di ImgSzR = aDSMIm2.sz();

    GenIm::type_el aTypeIm1 = aDSMIm1.type_el();
    GenIm::type_el aTypeIm2 = aDSMIm2.type_el();

    cout<<"type of "<<aImg1<<": "<<aTypeIm1<<endl;
    cout<<"type of "<<aImg2<<": "<<aTypeIm2<<endl;

    std::string aImgRef1 = aImg1;
    std::string aImgRef2 = aImg2;
    bool bTo8Bits1 = false;
    bool bTo8Bits2 = false;

    if(aTypeIm1 == 2)
    {
        aImgRef1 = aImg1 + "_to8Bits.tif";
        std::string aComto8Bits = MMBinFile(MM3DStr) + "to8Bits " + aImg1 + " Out=" + aImgRef1 + " Dyn=" + ToString(dDyn);
        cout<<aComto8Bits<<endl;
        System(aComto8Bits);
        bTo8Bits1 = true;
        //cout<<aImg1<<" transformed to "<<aImgRef1<<endl;
    }
    if(aTypeIm2 == 2)
    {
        aImgRef2 = aImg2 + "_to8Bits.tif";
        std::string aComto8Bits = MMBinFile(MM3DStr) + "to8Bits " + aImg2 + " Out=" + aImgRef2 + " Dyn=" + ToString(dDyn);
        cout<<aComto8Bits<<endl;
        System(aComto8Bits);
        bTo8Bits2 = true;
        //cout<<aImg2<<" transformed to "<<aImgRef2<<endl;
    }

    Pt2dr origin = Pt2dr(0, 0);

    std::vector<std::string> vPatchesL, vPatchesR;
    std::vector<cElHomographie> vHomoL, vHomoR;

    std::list<std::string> aLComClip, aRComClip;

    Pt2dr aPatchNumL = ClipImg(aRotateOutImg1, aImgRef1, ImgSzL, aPatchSz, aBufferSz, origin, aOutDir, aLComClip, vPatchesL, vHomoL);
    Pt2dr aPatchNumR = ClipImg(aOutImg2, aImgRef2, ImgSzR, aPatchSz, aBufferSz, origin, aOutDir, aRComClip, vPatchesR, vHomoR);

    cout<<"Number of tile pairs: "<<aPatchNumL.x*aPatchNumL.y*aPatchNumR.x*aPatchNumR.y<<endl;

    std::vector<string> vaImgPair;
    for(unsigned int i=0; i<vPatchesL.size(); i++)
    {
        for(unsigned int j=0; j<vPatchesR.size(); j++)
        {
            vaImgPair.push_back(vPatchesL[i] + " " + vPatchesR[j]);
        }
    }

    //write SuperGlueInput.txt
    //std::string aDir = "/home/lulin/Documents/zll/TestLulinCodeInMicMac/SpGlue/new/";
    FILE * fpOutput = fopen((aOutDir+aImgPair).c_str(), "w");
    int nPairNum = vaImgPair.size();
    for(int i=0; i<nPairNum; i++)
    {
        fprintf(fpOutput, "%s", vaImgPair[i].c_str());
        if(i<nPairNum-1)
            fprintf(fpOutput, "\n");
    }
    fclose(fpOutput);

    //transform the homography
    int nHomoLNum = vHomoL.size();
    for(int i=0; i<nHomoLNum; i++)
    {
        vHomoL[i] = aIm1_OriImg1*vHomoL[i];
    }

    WriteXml(aOriOutImg1, aOutImg2, aOutDir+aSubPatchXml, vPatchesL, vPatchesR, vHomoL, vHomoR, bPrint);

    cEl_GPAO::DoComInParal(aLComClip);
    cEl_GPAO::DoComInParal(aRComClip);

    if(bTo8Bits1 == true)
    {
        std::string aComRemove ="rm -r " + aImgRef1;
        System(aComRemove);
        cout<<aComRemove<<endl;
    }
    if(bTo8Bits2 == true)
    {
        std::string aComRemove ="rm -r " + aImgRef2;
        System(aComRemove);
        cout<<aComRemove<<endl;
    }
}

int BruteForce(int argc,char ** argv, const std::string &aArg="")
{
    cCommonAppliTiepHistorical aCAS3D;

    std::string aImg1;
    std::string aImg2;

    std::string aType;

    //bool bRotate = false;

    Pt2dr aPatchSz(640, 480);
    Pt2dr aBufferSz(0,0);

    std::string aOutDir = "./Tmp_Patches-CoReg";
    double dDyn = 0.1;

    int aRotate = -1;

    ElInitArgMain
     (
         argc,argv,
         LArgMain()
                << EAMC(aType,"BruteForce or Guided")
                     << EAMC(aImg1,"Master image name")
                     << EAMC(aImg2,"Secondary image name"),
         LArgMain()
                << EAM(aPatchSz, "PatchSz", true, "Patch size of the tiling scheme, which means the images to be matched by SuperGlue will be split into patches of this size, Def=[640, 480]")
                << EAM(aBufferSz, "BufferSz", true, "Buffer zone size around the patch of the tiling scheme, Def=[0,0]")
                //<< EAM(bRotate,"Rotate",true,"Rotate the master image by 90 degree 4 times for matching methods which are not invariant to rotation (e.g. SuperGlue), Def=false")
                << EAM(aRotate,"Rotate",true,"The angle of clockwise rotation from the master image to the secondary image (only 4 options available: 0, 90, 180, 270, as SuperGlue is invariant to rotation smaller than 45 degree.), Def=-1 (means all the 4 options will be executed, and the one with the most inlier will be kept) ")
                << EAM(aOutDir, "OutDir", true, "Output direcotry of the patches, Def=./Tmp_Patches-CoReg")
                << aCAS3D.ArgBasic()
                << aCAS3D.ArgGetPatchPair()
                << EAM(dDyn, "Dyn", true, "The Dyn parameter in \"to8Bits\" if the input RGB images are 16 bits, Def=0.1")
     );

    aOutDir += "/";
    ELISE_fp::MkDir(aOutDir);

    std::string aOutImg1 = GetFolderName(aImg1);
    if(aOutImg1.length() == 0) //means there is no folder
        aOutImg1 = aImg1;
    else
        aOutImg1 += "." + StdPostfix(aImg1);
    std::string aOutImg2 = GetFolderName(aImg2);
    if(aOutImg2.length() == 0)
        aOutImg2 = aImg2;
    else
        aOutImg2 += "." + StdPostfix(aImg2);

    Tiff_Im aDSMIm1((aCAS3D.mDir+aImg1).c_str());
    Pt2di ImgSzL = aDSMIm1.sz();

    std::string aImg1_Rotate;
    std::string aOutImg1_Rotate;
    std::string aSubPatchXml;
    std::string aImgPair;
    std::string aImgBase = aImg1;

    //no rotation
   if(aRotate == -1)
   {
       cElComposHomographie aUnitHX(1, 0, 0);
       cElComposHomographie aUnitHY(0, 1, 0);
       cElComposHomographie aUnitHZ(0, 0, 1);
       cElHomographie  aUnitH =  cElHomographie(aUnitHX,aUnitHY,aUnitHZ);

       //no rotation
       GetTilePair(aOutDir, aOutImg1, aOutImg1, aOutImg2, aImg1, aImg2, aPatchSz, aBufferSz, aCAS3D.mImgPair, aCAS3D.mDir, aCAS3D.mSubPatchXml, aImg1, aUnitH, aCAS3D.mPrint, dDyn);
   }
       //rotate 90 degree
       else if(aRotate == 90)
       {
           cElComposHomographie aRotateHX(0, 1, 0);
           cElComposHomographie aRotateHY(-1, 0, ImgSzL.y);
           cElComposHomographie aRotateHZ(0, 0, 1);
           cElHomographie  aRotateH =  cElHomographie(aRotateHX,aRotateHY,aRotateHZ);
           aRotateH.Show();

           aImg1_Rotate = StdPrefix(aImgBase)+"_R90."+StdPostfix(aImgBase);
           aOutImg1_Rotate = StdPrefix(aOutImg1)+"_R90."+StdPostfix(aOutImg1);
           aSubPatchXml = StdPrefix(aCAS3D.mSubPatchXml)+"_R90."+StdPostfix(aCAS3D.mSubPatchXml);
           aImgPair = StdPrefix(aCAS3D.mImgPair)+"_R90."+StdPostfix(aCAS3D.mImgPair);

           //cout<<aImg1_Rotate<<",,,"<<aSubPatchXml<<",,,"<<aImgPair<<endl;

           RotateImgBy90Deg(aCAS3D.mDir, aImgBase, aImg1_Rotate);
           GetTilePair(aOutDir, aOutImg1, aOutImg1_Rotate, aOutImg2, aImg1_Rotate, aImg2, aPatchSz, aBufferSz, aImgPair, aCAS3D.mDir, aSubPatchXml, aImg1, aRotateH, aCAS3D.mPrint, dDyn);
       }
       //rotate 180 degree
       else if(aRotate == 180)
       {
           cElComposHomographie aRotateHX(-1, 0, ImgSzL.x);
           cElComposHomographie aRotateHY(0, -1, ImgSzL.y);
           cElComposHomographie aRotateHZ(0, 0, 1);
           cElHomographie  aRotateH =  cElHomographie(aRotateHX,aRotateHY,aRotateHZ);
           aRotateH.Show();

           aImg1_Rotate = StdPrefix(aImgBase)+"_R180."+StdPostfix(aImgBase);
           aOutImg1_Rotate = StdPrefix(aOutImg1)+"_R180."+StdPostfix(aOutImg1);
           aSubPatchXml = StdPrefix(aCAS3D.mSubPatchXml)+"_R180."+StdPostfix(aCAS3D.mSubPatchXml);
           aImgPair = StdPrefix(aCAS3D.mImgPair)+"_R180."+StdPostfix(aCAS3D.mImgPair);

           //cout<<aImg1_Rotate<<",,,"<<aSubPatchXml<<",,,"<<aImgPair<<endl;

           RotateImgBy90DegNTimes(aCAS3D.mDir, aImgBase, aImg1_Rotate, 2);
           GetTilePair(aOutDir, aOutImg1, aOutImg1_Rotate, aOutImg2, aImg1_Rotate, aImg2, aPatchSz, aBufferSz, aImgPair, aCAS3D.mDir, aSubPatchXml, aImg1, aRotateH, aCAS3D.mPrint, dDyn);
       }
       //rotate 270 degree
       else if(aRotate == 270)
       {
           cElComposHomographie aRotateHX(0, -1, ImgSzL.x);
           cElComposHomographie aRotateHY(1, 0, 0);
           cElComposHomographie aRotateHZ(0, 0, 1);
           cElHomographie  aRotateH =  cElHomographie(aRotateHX,aRotateHY,aRotateHZ);
           aRotateH.Show();

           aImg1_Rotate = StdPrefix(aImgBase)+"_R270."+StdPostfix(aImgBase);
           aOutImg1_Rotate = StdPrefix(aOutImg1)+"_R270."+StdPostfix(aOutImg1);
           aSubPatchXml = StdPrefix(aCAS3D.mSubPatchXml)+"_R270."+StdPostfix(aCAS3D.mSubPatchXml);
           aImgPair = StdPrefix(aCAS3D.mImgPair)+"_R270."+StdPostfix(aCAS3D.mImgPair);

           //cout<<aImg1_Rotate<<",,,"<<aSubPatchXml<<",,,"<<aImgPair<<endl;

           RotateImgBy90DegNTimes(aCAS3D.mDir, aImgBase, aImg1_Rotate, 3);
           GetTilePair(aOutDir, aOutImg1, aOutImg1_Rotate, aOutImg2, aImg1_Rotate, aImg2, aPatchSz, aBufferSz, aImgPair, aCAS3D.mDir, aSubPatchXml, aImg1, aRotateH, aCAS3D.mPrint, dDyn);
       }
    //}

    return 0;
}

int Guided(int argc,char ** argv, const std::string &aArg="")
{
    cCommonAppliTiepHistorical aCAS3D;

    std::string aImg1;
    std::string aImg2;
    std::string aOri1;
    std::string aOri2;

    std::string aType;

    std::string aPara3DH = "";

    //bool bPrint = false;

    std::string aDSMDirL = "";
    std::string aDSMFileL;
    aDSMFileL = "MMLastNuage.xml";
    std::string aPrefix = "";

    double aThres = 2;

    double dDyn = 0.1;

    Pt2dr aPatchSz(640, 480);
    Pt2dr aBufferSz(-1,-1);

    std::string aOutDir = "./Tmp_Patches-Precise";

    ElInitArgMain
     (
         argc,argv,
         LArgMain()
                << EAMC(aType,"BruteForce or Guided")
                     << EAMC(aImg1,"Master image name")
                     << EAMC(aImg2,"Secondary image name")
                     << EAMC(aOri1,"Orientation of master image")
                     << EAMC(aOri2,"Orientation of secondary image"),
         LArgMain()
                     << aCAS3D.ArgBasic()
                     << aCAS3D.ArgGetPatchPair()
                << EAM(aPatchSz, "PatchSz", true, "Patch size of the tiling scheme, which means the images to be matched by SuperGlue will be split into patches of this size, Def=[640, 480]")
                << EAM(aBufferSz, "BufferSz", true, "Buffer zone size around the patch of the tiling scheme, Def=10%*PatchSz")
                << EAM(aPara3DH, "Para3DH", false, "Input xml file that recorded the paremeter of the 3D Helmert transformation from orientation of master image to secondary image, Def=none")
                //<< EAM(bPrint, "Print", false, "Print corner coordinate, Def=false")
                << EAM(aDSMDirL, "DSMDirL", true, "DSM directory of master image, Def=none")
                << EAM(aDSMFileL, "DSMFileL", true, "DSM File of master image, Def=MMLastNuage.xml")
                << EAM(aPrefix, "Prefix", true, "The prefix for the name of images (for debug only), Def=none")
                << EAM(aThres, "Thres", true, "The threshold of reprojection error (unit: pixel) when prejecting patch corner to DSM, Def=2")
                << EAM(aOutDir, "OutDir", true, "Output direcotry of the patches, Def=./Tmp_Patches-Precise")
                << EAM(dDyn, "Dyn", true, "The Dyn parameter in \"to8Bits\" if the input RGB images are 16 bits, Def=0.1")
     );

    if(aBufferSz.x < 0 && aBufferSz.y < 0){
        aBufferSz.x = int(0.1*aPatchSz.x);
        aBufferSz.y = int(0.1*aPatchSz.y);
    }

    aOutDir += "/";
    ELISE_fp::MkDir(aOutDir);

    StdCorrecNameOrient(aOri1,"./",true);
    StdCorrecNameOrient(aOri2,"./",true);

/*
     std::string aKeyOri1 = "NKS-Assoc-Im2Orient@-" + aOri1;
     std::string aKeyOri2 = "NKS-Assoc-Im2Orient@-" + aOri2;

     std::string aIm1OriFile = aCAS3D.mICNM->Assoc1To1(aKeyOri1,aImg1,true);
     std::string aIm2OriFile = aCAS3D.mICNM->Assoc1To1(aKeyOri2,aImg2,true);

    if (aPara3DH.length() > 0 && ELISE_fp::exist_file(aPara3DH) == false)
    {
        printf("File %s does not exist.\n", aPara3DH.c_str());
         return 0;
     }
*/
    cTransform3DHelmert aTrans3DH(aPara3DH);

    std::string aOutImg1 = GetFileName(aImg1);
    std::string aOutImg2 = GetFileName(aImg2);
    GetPatchPair(aOutDir, aOutImg1, aOutImg2, aImg1, aImg2, aOri1, aOri2, aCAS3D.mICNM, aPatchSz, aBufferSz, aPrefix + aCAS3D.mImgPair, aCAS3D.mDir, aPrefix + aCAS3D.mSubPatchXml, aTrans3DH, aDSMFileL, aDSMDirL, aThres, dDyn, aCAS3D.mPrint, aPrefix);

    return 0;
}

int GetPatchPair_main(int argc,char ** argv)
{
    bool aModeHelp=true;
    eGetPatchPair_HistoP aType=eNbTypePPHP;
    StdReadEnum(aModeHelp,aType,argv[1],eNbTypePPHP);

   std::string TheType = argv[1];

   if (TheType == "BruteForce")
   {
       int aRes = BruteForce(argc, argv, TheType);
       return aRes;
   }
   else if (TheType == "Guided")
   {
       int aRes = Guided(argc, argv, TheType);
       return aRes;
   }

   return EXIT_SUCCESS;
}
