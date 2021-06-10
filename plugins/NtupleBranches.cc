#include "../interface/NtupleBranches.h"

//===================================================================================================================        
NtupleBranches::NtupleBranches( std::map< std::string, bool >& runFlags, TTree* tree )
   : tree_( tree )
{
   branch( runFlags );
}

//===================================================================================================================
NtupleBranches::~NtupleBranches( void )
{
}

//===================================================================================================================      
void NtupleBranches::branch( std::map< std::string, bool >& runFlags ){


    if ( runFlags["runOnMC"] ){
    if ( runFlags["doGenParticles"] ){
      /** genParticles */
      tree_->Branch( "genParticle_N"	     , &genParticle_N	       );
      tree_->Branch( "genParticle_pt"	     , &genParticle_pt	       ); 
//      tree_->Branch( "genParticle_px"	     , &genParticle_px	       ); 
//      tree_->Branch( "genParticle_py"	     , &genParticle_py	       ); 
//      tree_->Branch( "genParticle_pz"	     , &genParticle_pz	       ); 
//      tree_->Branch( "genParticle_e" 	     , &genParticle_e	       ); 
      tree_->Branch( "genParticle_eta"	     , &genParticle_eta        ); 
      tree_->Branch( "genParticle_phi"	     , &genParticle_phi        ); 
      tree_->Branch( "genParticle_mass"	     , &genParticle_mass       ); 
      tree_->Branch( "genParticle_pdgId"     , &genParticle_pdgId      );
      tree_->Branch( "genParticle_status"    , &genParticle_status     );
      tree_->Branch( "genParticle_isPrompt"  , &genParticle_isPrompt   );
      tree_->Branch( "genParticle_isDirectPromptTauDecayProduct"  , &genParticle_isDirectPromptTauDecayProduct);
      tree_->Branch( "genParticle_isDirectHardProcessTauDecayProductFinalState"  , &genParticle_isDirectHardProcessTauDecayProductFinalState);
      tree_->Branch( "genParticle_fromHardProcessFinalState"  , &genParticle_fromHardProcessFinalState   );
      tree_->Branch( "genParticle_mother"    , &genParticle_mother     );
      tree_->Branch( "genParticle_nMoth"     , &genParticle_nMoth      );
      tree_->Branch( "genParticle_nDau"	     , &genParticle_nDau       ); 
      tree_->Branch( "genParticle_dau"	     , &genParticle_dau        );
    
      
 
    } //doGenParticles
    
    if ( runFlags["doGenEvent"] ){
      /** generator info */
      tree_->Branch( "lheV_pt"	             , &lheV_pt                ); 
      tree_->Branch( "lheHT"	             , &lheHT                  ); 
      tree_->Branch( "lheNj"	             , &lheNj                  );
      tree_->Branch( "lheNb"	             , &lheNb                  );
      tree_->Branch( "lheNl"	             , &lheNl                  );
      tree_->Branch( "lheV_mass"           , &lheV_mass              ); 
      tree_->Branch( "genWeight"	         , &genWeight              );
      tree_->Branch( "genFacWeightUp"	     , &genFacWeightUp         );
      tree_->Branch( "genFacWeightDown"	   , &genFacWeightDown       );
      tree_->Branch( "genRenWeightUp"	     , &genRenWeightUp         );
      tree_->Branch( "genRenWeightDown"	   , &genRenWeightDown       );
      tree_->Branch( "genFacRenWeightUp"	 , &genFacRenWeightUp      );
      tree_->Branch( "genFacRenWeightDown" , &genFacRenWeightDown    );
      tree_->Branch( "qScale"	             , &qScale                 );
      tree_->Branch( "PDF_rms"	           , &PDF_rms                );
      tree_->Branch( "PDF_x"	             , &PDF_x                  );
      tree_->Branch( "PDF_xPDF"	           , &PDF_xPDF               );
      tree_->Branch( "PDF_id"	             , &PDF_id                 );

    } //doGenEvent
  } //runOnMC
  
  
  if (runFlags["doTriggerDecisions"]) {
    /** HLT trigger decisions */
    tree_->Branch("HLT_BPH_isFired", &HLT_BPH_isFired );
  }

  
  if (runFlags["doTriggerObjects"]) {
    /** HLT trigger objects */
    tree_->Branch("triggerObject_pt"		, &triggerObject_pt		);
    tree_->Branch("triggerObject_eta"		, &triggerObject_eta		);
    tree_->Branch("triggerObject_phi"		, &triggerObject_phi	        );
    tree_->Branch("triggerObject_mass"		, &triggerObject_mass	        );
    tree_->Branch("triggerObject_lastname"	, &triggerObject_lastname	);
    tree_->Branch("triggerObject_filterLabels"	, &triggerObject_filterLabels	);
    tree_->Branch("triggerObject_firedTrigger"	, &triggerObject_firedTrigger	);
    tree_->Branch("triggerObject_filterIDs"	, &triggerObject_filterIDs	);

  } //doTriggerObjects
  
  if (runFlags["doHltFilters"]) {
    /** HLT filter decisions */
    tree_->Branch("passFilter_HBHE"                 ,&passFilter_HBHE_                ,"passFilter_HBHE_/O");
    tree_->Branch("passFilter_HBHELoose"            ,&passFilter_HBHELoose_	          ,"passFilter_HBHELoose_/O");
    tree_->Branch("passFilter_HBHETight"            ,&passFilter_HBHETight_	          ,"passFilter_HBHETight_/O");
    tree_->Branch("passFilter_HBHEIso"              ,&passFilter_HBHEIso_	            ,"passFilter_HBHEIso_/O");
    tree_->Branch("passFilter_CSCHalo"              ,&passFilter_CSCHalo_             ,"passFilter_CSCHalo_/O");
    tree_->Branch("passFilter_CSCTightHalo2015"     ,&passFilter_CSCTightHalo2015_    ,"passFilter_CSCTightHalo2015_/O");
    tree_->Branch("passFilter_HCALlaser"            ,&passFilter_HCALlaser_           ,"passFilter_HCALlaser_/O");
    tree_->Branch("passFilter_ECALDeadCell"         ,&passFilter_ECALDeadCell_        ,"passFilter_ECALDeadCell_/O");
    tree_->Branch("passFilter_GoodVtx"              ,&passFilter_GoodVtx_             ,"passFilter_GoodVtx_/O");
    tree_->Branch("passFilter_TrkFailure"           ,&passFilter_TrkFailure_          ,"passFilter_TrkFailure_/O");
    tree_->Branch("passFilter_EEBadSc"              ,&passFilter_EEBadSc_             ,"passFilter_EEBadSc_/O");
    tree_->Branch("passFilter_ECALlaser"            ,&passFilter_ECALlaser_           ,"passFilter_ECALlaser_/O");
    tree_->Branch("passFilter_TrkPOG"               ,&passFilter_TrkPOG_              ,"passFilter_TrkPOG_/O");
    tree_->Branch("passFilter_TrkPOG_manystrip"     ,&passFilter_TrkPOG_manystrip_    ,"passFilter_TrkPOG_manystrip_/O");
    tree_->Branch("passFilter_TrkPOG_toomanystrip"  ,&passFilter_TrkPOG_toomanystrip_ ,"passFilter_TrkPOG_toomanystrip_/O");
    tree_->Branch("passFilter_TrkPOG_logError"      ,&passFilter_TrkPOG_logError_     ,"passFilter_TrkPOG_logError_/O");
    tree_->Branch("passFilter_METFilters"           ,&passFilter_METFilters_          ,"passFilter_METFilters_/O");
    
     //NEW FOR ICHEP
    tree_->Branch("passFilter_CSCTightHaloTrkMuUnvetoFilter", &passFilter_CSCTightHaloTrkMuUnvetoFilter_   ,"passFilter_CSCTightHaloTrkMuUnvetoFilter_/O");
    tree_->Branch("passFilter_globalTightHalo2016"          , &passFilter_globalTightHalo2016_             ,"passFilter_globalTightHalo2016_/O");
    tree_->Branch("passFilter_globalSuperTightHalo2016"          , &passFilter_globalSuperTightHalo2016_             ,"passFilter_globalSuperTightHalo2016_/O");
    tree_->Branch("passFilter_HcalStripHalo"                , &passFilter_HcalStripHalo_                   ,"passFilter_HcalStripHalo_/O");
    tree_->Branch("passFilter_chargedHadronTrackResolution" , &passFilter_chargedHadronTrackResolution_    ,"passFilter_chargedHadronTrackResolution_/O");
    tree_->Branch("passFilter_muonBadTrack"                 , &passFilter_muonBadTrack_                    ,"passFilter_muonBadTrack_/O");
    tree_->Branch("flag_badMuons"                 , &flag_badMuons_                    ,"flag_badMuons_/O");
    tree_->Branch("flag_duplicateMuons"                 , &flag_duplicateMuons_                    ,"flag_duplicateMuons_/O");
    tree_->Branch("flag_nobadMuons"                 , &flag_nobadMuons_                    ,"flag_nobadMuons_/O");
    tree_->Branch("passFilter_ecalBadCalib_"    ,&passFilter_ecalBadCalib_, "passFilter_ecalBadCalib_/O");
  } //do HltFilters

  if (runFlags["doMissingEt"]) {
    /** MET */
    tree_->Branch( "rho", &rho );
    tree_->Branch("METraw_et"		        , &METraw_et	     );
    tree_->Branch("METraw_phi"		        , &METraw_phi	     ); 
    tree_->Branch("METraw_sumEt"		, &METraw_sumEt	     );   
    tree_->Branch("MET_corrPx"		        , &MET_corrPx	     ); 
    tree_->Branch("MET_corrPy"		        , &MET_corrPy	     );   
    tree_->Branch("MET_et"	                , &MET_et  	     ); 
    tree_->Branch("MET_phi"	                , &MET_phi           );
    tree_->Branch("MET_puppi_et"	        , &MET_puppi_et      ); 
    tree_->Branch("MET_puppi_phi"               , &MET_puppi_phi     );
    tree_->Branch("MET_sumEt"	                , &MET_sumEt 	     ); 
    tree_->Branch("MET_JetEnUp"	                , &MET_JetEnUp 	     ); 
    tree_->Branch("MET_JetEnDown"	                , &MET_JetEnDown 	     ); 
    tree_->Branch("MET_JetResUp"	                , &MET_JetResUp 	     ); 
    tree_->Branch("MET_JetResDown"	                , &MET_JetResDown 	     ); 
    tree_->Branch("MET_UnclusteredEnUp"	                , &MET_UnclusteredEnUp 	     ); 
    tree_->Branch("MET_UnclusteredEnDown"	                , &MET_UnclusteredEnDown 	     ); 
    
  } //doMissingEt

  if ( runFlags["doMVAMET"] ){
    /** MET SVift*/
    tree_->Branch("MET_Nmva"	                , &MET_Nmva 	     ); 
    tree_->Branch("MET_mva_et"	                , &MET_mva_et        ); 
    tree_->Branch("MET_mva_phi"                 , &MET_mva_phi       );
    tree_->Branch( "MET_mva_cov00"                                        , &MET_mva_cov00 );
    tree_->Branch( "MET_mva_cov10"                                        , &MET_mva_cov10 );
    tree_->Branch( "MET_mva_cov11"                                        , &MET_mva_cov11 );
    tree_->Branch( "MET_mva_recoil_pt"                                        , &MET_mva_recoil_pt );
    tree_->Branch( "MET_mva_recoil_eta"                                        , &MET_mva_recoil_eta );
    tree_->Branch( "MET_mva_recoil_phi"                                        , &MET_mva_recoil_phi );
    tree_->Branch( "MET_mva_recoil_pdgId"                                        , &MET_mva_recoil_pdgId );

  }

  
  /*------------- ------EVENT infos-----------------------------*/
  tree_->Branch("EVENT_event"	 , &EVENT_event     );
  tree_->Branch("EVENT_run"	 , &EVENT_run	    );
  tree_->Branch("EVENT_lumiBlock", &EVENT_lumiBlock );
  
  if (runFlags["runOnMC"]) {
    if (runFlags["doPileUp"]) {
      /*--------------------------PU infos--------------------------*/
      tree_->Branch("nPuVtxTrue", &nPuVtxTrue );	
      tree_->Branch("nPuVtx"    , &nPuVtx     );
      tree_->Branch("bX"	, &bX	      );
    } //doPileUp
  } //runOnMC
  
  if (runFlags["doVertices"]) {  
    /*--------------------------PV infos--------------------------*/
    tree_->Branch("PV_N"     , &PV_N      );
    tree_->Branch("PV_filter", &PV_filter );
    tree_->Branch("PV_chi2"  , &PV_chi2   );
    tree_->Branch("PV_ndof"  , &PV_ndof   );
    tree_->Branch("PV_rho"   , &PV_rho    );
    tree_->Branch("PV_z"     , &PV_z      );
    tree_->Branch("BeamSpot_x0" , &BeamSpot_x0     );
    tree_->Branch("BeamSpot_y0" , &BeamSpot_y0     );
    tree_->Branch("BeamSpot_z0" , &BeamSpot_z0     );


  }

  // change
  if ( runFlags["doAllParticles"] ){
    /** genParticles */
    tree_->Branch( "allParticle_N"     , &allParticle_N      );
    tree_->Branch( "allParticle_charge", &allParticle_charge ); 
    tree_->Branch( "allParticle_pt"    , &allParticle_pt     ); 
    tree_->Branch( "allParticle_eta"   , &allParticle_eta    ); 
    tree_->Branch( "allParticle_phi"   , &allParticle_phi    ); 
    tree_->Branch( "allParticle_dxy"   , &allParticle_dxy    ); 
    tree_->Branch( "allParticle_dz"    , &allParticle_dz     ); 
    tree_->Branch( "allParticle_exy"   , &allParticle_exy    ); 
    tree_->Branch( "allParticle_ez"    , &allParticle_ez     ); 
  }


  if (runFlags["doJpsiMu"]){
    tree_->Branch("IsJpsiMu" , &IsJpsiMu  );

    tree_->Branch("JpsiMu_nCandidates", &JpsiMu_nCandidates );

    tree_->Branch("JpsiMu_mu1_pt", &JpsiMu_mu1_pt );
    tree_->Branch("JpsiMu_mu1_eta", &JpsiMu_mu1_eta );
    tree_->Branch("JpsiMu_mu1_phi", &JpsiMu_mu1_phi );
    tree_->Branch("JpsiMu_mu1_mass", &JpsiMu_mu1_mass );
    tree_->Branch("JpsiMu_mu1_unfit_pt", &JpsiMu_mu1_unfit_pt );
    tree_->Branch("JpsiMu_mu1_unfit_eta", &JpsiMu_mu1_unfit_eta );
    tree_->Branch("JpsiMu_mu1_unfit_phi", &JpsiMu_mu1_unfit_phi );
    tree_->Branch("JpsiMu_mu1_unfit_mass", &JpsiMu_mu1_unfit_mass );
    tree_->Branch("JpsiMu_mu1_q", &JpsiMu_mu1_q );
    tree_->Branch("JpsiMu_mu1_isLoose"  , &JpsiMu_mu1_isLoose   );
    tree_->Branch("JpsiMu_mu1_isTight"  , &JpsiMu_mu1_isTight   );
    tree_->Branch("JpsiMu_mu1_isPF"     , &JpsiMu_mu1_isPF      );
    tree_->Branch("JpsiMu_mu1_isGlobal" , &JpsiMu_mu1_isGlobal  );
    tree_->Branch("JpsiMu_mu1_isTracker", &JpsiMu_mu1_isTracker );
    tree_->Branch("JpsiMu_mu1_isSoft"   , &JpsiMu_mu1_isSoft    );
    tree_->Branch("JpsiMu_mu1_vx"   , &JpsiMu_mu1_vx    );
    tree_->Branch("JpsiMu_mu1_vy"   , &JpsiMu_mu1_vy    );
    tree_->Branch("JpsiMu_mu1_vz"   , &JpsiMu_mu1_vz    );
    tree_->Branch("JpsiMu_mu1_iso"   , &JpsiMu_mu1_iso    );
    tree_->Branch("JpsiMu_mu1_dbiso"   , &JpsiMu_mu1_dbiso    );

    tree_->Branch("JpsiMu_mu2_pt", &JpsiMu_mu2_pt );
    tree_->Branch("JpsiMu_mu2_eta", &JpsiMu_mu2_eta );
    tree_->Branch("JpsiMu_mu2_phi", &JpsiMu_mu2_phi );
    tree_->Branch("JpsiMu_mu2_mass", &JpsiMu_mu2_mass );
    tree_->Branch("JpsiMu_mu2_unfit_pt", &JpsiMu_mu2_unfit_pt );
    tree_->Branch("JpsiMu_mu2_unfit_eta", &JpsiMu_mu2_unfit_eta );
    tree_->Branch("JpsiMu_mu2_unfit_phi", &JpsiMu_mu2_unfit_phi );
    tree_->Branch("JpsiMu_mu2_unfit_mass", &JpsiMu_mu2_unfit_mass );
    tree_->Branch("JpsiMu_mu2_q", &JpsiMu_mu2_q );
    tree_->Branch("JpsiMu_mu2_isLoose"  , &JpsiMu_mu2_isLoose   );
    tree_->Branch("JpsiMu_mu2_isTight"  , &JpsiMu_mu2_isTight   );
    tree_->Branch("JpsiMu_mu2_isPF"     , &JpsiMu_mu2_isPF      );
    tree_->Branch("JpsiMu_mu2_isGlobal" , &JpsiMu_mu2_isGlobal  );
    tree_->Branch("JpsiMu_mu2_isTracker", &JpsiMu_mu2_isTracker );
    tree_->Branch("JpsiMu_mu2_isSoft"   , &JpsiMu_mu2_isSoft    );
    tree_->Branch("JpsiMu_mu2_vx"   , &JpsiMu_mu2_vx    );
    tree_->Branch("JpsiMu_mu2_vy"   , &JpsiMu_mu2_vy    );
    tree_->Branch("JpsiMu_mu2_vz"   , &JpsiMu_mu2_vz    );
    tree_->Branch("JpsiMu_mu2_iso"   , &JpsiMu_mu2_iso    );
    tree_->Branch("JpsiMu_mu2_dbiso"   , &JpsiMu_mu2_dbiso    );

    tree_->Branch("JpsiMu_mu3_pt", &JpsiMu_mu3_pt );
    tree_->Branch("JpsiMu_mu3_eta", &JpsiMu_mu3_eta );
    tree_->Branch("JpsiMu_mu3_phi", &JpsiMu_mu3_phi );
    tree_->Branch("JpsiMu_mu3_mass", &JpsiMu_mu3_mass );
    tree_->Branch("JpsiMu_mu3_unfit_pt", &JpsiMu_mu3_unfit_pt );
    tree_->Branch("JpsiMu_mu3_unfit_eta", &JpsiMu_mu3_unfit_eta );
    tree_->Branch("JpsiMu_mu3_unfit_phi", &JpsiMu_mu3_unfit_phi );
    tree_->Branch("JpsiMu_mu3_unfit_mass", &JpsiMu_mu3_unfit_mass );
    tree_->Branch("JpsiMu_mu3_doca2mu1", &JpsiMu_mu3_doca2mu1 );
    tree_->Branch("JpsiMu_mu3_doca2mu2", &JpsiMu_mu3_doca2mu2 );
    tree_->Branch("JpsiMu_mu3_q", &JpsiMu_mu3_q );
    tree_->Branch("JpsiMu_mu3_isLoose"  , &JpsiMu_mu3_isLoose   );
    tree_->Branch("JpsiMu_mu3_isTight"  , &JpsiMu_mu3_isTight   );
    tree_->Branch("JpsiMu_mu3_isPF"     , &JpsiMu_mu3_isPF      );
    tree_->Branch("JpsiMu_mu3_isGlobal" , &JpsiMu_mu3_isGlobal  );
    tree_->Branch("JpsiMu_mu3_isTracker", &JpsiMu_mu3_isTracker );
    tree_->Branch("JpsiMu_mu3_isSoft"   , &JpsiMu_mu3_isSoft    );
    tree_->Branch("JpsiMu_mu3_vx"   , &JpsiMu_mu3_vx    );
    tree_->Branch("JpsiMu_mu3_vy"   , &JpsiMu_mu3_vy    );
    tree_->Branch("JpsiMu_mu3_vz"   , &JpsiMu_mu3_vz    );
    tree_->Branch("JpsiMu_mu3_iso"   , &JpsiMu_mu3_iso    );
    tree_->Branch("JpsiMu_mu3_dbiso"   , &JpsiMu_mu3_dbiso    );

    tree_->Branch("JpsiMu_PV_vx", &JpsiMu_PV_vx );
    tree_->Branch("JpsiMu_PV_vy", &JpsiMu_PV_vy );
    tree_->Branch("JpsiMu_PV_vz", &JpsiMu_PV_vz );

    tree_->Branch("JpsiMu_bbPV_vx", &JpsiMu_bbPV_vx );
    tree_->Branch("JpsiMu_bbPV_vy", &JpsiMu_bbPV_vy );
    tree_->Branch("JpsiMu_bbPV_vz", &JpsiMu_bbPV_vz );

    tree_->Branch("JpsiMu_bbPV_refit_vx", &JpsiMu_bbPV_vx );
    tree_->Branch("JpsiMu_bbPV_refit_vy", &JpsiMu_bbPV_vy );
    tree_->Branch("JpsiMu_bbPV_refit_vz", &JpsiMu_bbPV_vz );

    tree_->Branch("JpsiMu_genPV_vx", &JpsiMu_genPV_vx );
    tree_->Branch("JpsiMu_genPV_vy", &JpsiMu_genPV_vy );
    tree_->Branch("JpsiMu_genPV_vz", &JpsiMu_genPV_vz );

    tree_->Branch("JpsiMu_Jpsi_pt", &JpsiMu_Jpsi_pt );
    tree_->Branch("JpsiMu_Jpsi_eta", &JpsiMu_Jpsi_eta );
    tree_->Branch("JpsiMu_Jpsi_phi", &JpsiMu_Jpsi_phi );
    tree_->Branch("JpsiMu_Jpsi_mass", &JpsiMu_Jpsi_mass );
    tree_->Branch("JpsiMu_Jpsi_vprob", &JpsiMu_Jpsi_vprob );
    tree_->Branch("JpsiMu_Jpsi_lip", &JpsiMu_Jpsi_lip);
    tree_->Branch("JpsiMu_Jpsi_lips", &JpsiMu_Jpsi_lips);
    tree_->Branch("JpsiMu_Jpsi_pvip", &JpsiMu_Jpsi_pvip);
    tree_->Branch("JpsiMu_Jpsi_pvips", &JpsiMu_Jpsi_pvips);
    tree_->Branch("JpsiMu_Jpsi_fl3d", &JpsiMu_Jpsi_fl3d);
    tree_->Branch("JpsiMu_Jpsi_fls3d", &JpsiMu_Jpsi_fls3d);
    tree_->Branch("JpsiMu_Jpsi_alpha", &JpsiMu_Jpsi_alpha);
    tree_->Branch("JpsiMu_Jpsi_maxdoca", &JpsiMu_Jpsi_maxdoca);
    tree_->Branch("JpsiMu_Jpsi_mindoca", &JpsiMu_Jpsi_mindoca);
    tree_->Branch("JpsiMu_Jpsi_vx", &JpsiMu_Jpsi_vx );
    tree_->Branch("JpsiMu_Jpsi_vy", &JpsiMu_Jpsi_vy );
    tree_->Branch("JpsiMu_Jpsi_vz", &JpsiMu_Jpsi_vz );
    tree_->Branch("JpsiMu_Jpsi_unfit_pt", &JpsiMu_Jpsi_unfit_pt );
    tree_->Branch("JpsiMu_Jpsi_unfit_mass", &JpsiMu_Jpsi_unfit_mass );
    tree_->Branch("JpsiMu_Jpsi_unfit_vprob", &JpsiMu_Jpsi_unfit_vprob );
    tree_->Branch("JpsiMu_Jpsi_unfit_vx", &JpsiMu_Jpsi_unfit_vx );
    tree_->Branch("JpsiMu_Jpsi_unfit_vy", &JpsiMu_Jpsi_unfit_vy );
    tree_->Branch("JpsiMu_Jpsi_unfit_vz", &JpsiMu_Jpsi_unfit_vz );


    tree_->Branch("JpsiMu_B_pt", &JpsiMu_B_pt );
    tree_->Branch("JpsiMu_B_eta", &JpsiMu_B_eta );
    tree_->Branch("JpsiMu_B_phi", &JpsiMu_B_phi );
    tree_->Branch("JpsiMu_B_mass", &JpsiMu_B_mass );
    tree_->Branch("JpsiMu_B_vprob", &JpsiMu_B_vprob );
    tree_->Branch("JpsiMu_B_lip", &JpsiMu_B_lip);
    tree_->Branch("JpsiMu_B_lips", &JpsiMu_B_lips);
    tree_->Branch("JpsiMu_B_pvip", &JpsiMu_B_pvip);
    tree_->Branch("JpsiMu_B_pvips", &JpsiMu_B_pvips);
    tree_->Branch("JpsiMu_B_fl3d", &JpsiMu_B_fl3d);
    tree_->Branch("JpsiMu_B_fls3d", &JpsiMu_B_fls3d);
    tree_->Branch("JpsiMu_B_alpha", &JpsiMu_B_alpha);
    tree_->Branch("JpsiMu_B_maxdoca", &JpsiMu_B_maxdoca);
    tree_->Branch("JpsiMu_B_mindoca", &JpsiMu_B_mindoca);
    tree_->Branch("JpsiMu_B_vx", &JpsiMu_B_vx );
    tree_->Branch("JpsiMu_B_vy", &JpsiMu_B_vy );
    tree_->Branch("JpsiMu_B_vz", &JpsiMu_B_vz );
    tree_->Branch("JpsiMu_B_iso", &JpsiMu_B_iso);
    tree_->Branch("JpsiMu_B_iso_ntracks", &JpsiMu_B_iso_ntracks );
    tree_->Branch("JpsiMu_B_iso_mindoca", &JpsiMu_B_iso_mindoca );
    tree_->Branch("JpsiMu_B_unfit_pt", &JpsiMu_B_unfit_pt );
    tree_->Branch("JpsiMu_B_unfit_mass", &JpsiMu_B_unfit_mass );
    tree_->Branch("JpsiMu_B_unfit_vprob", &JpsiMu_B_unfit_vprob );
    tree_->Branch("JpsiMu_B_unfit_vx", &JpsiMu_B_unfit_vx );
    tree_->Branch("JpsiMu_B_unfit_vy", &JpsiMu_B_unfit_vy );
    tree_->Branch("JpsiMu_B_unfit_vz", &JpsiMu_B_unfit_vz );

    tree_->Branch("JpsiMu_ngenmuons", &JpsiMu_ngenmuons);
    tree_->Branch("JpsiMu_isgenmatched", &JpsiMu_isgenmatched);
    tree_->Branch("JpsiMu_mu3_isgenmatched", &JpsiMu_mu3_isgenmatched);

  }



  if (runFlags["doJpsiTau"]){
    tree_->Branch("IsJpsiTau", &IsJpsiTau );

    tree_->Branch("JpsiTau_nCandidates", &JpsiTau_nCandidates );


    tree_->Branch("JpsiTau_mu1_pt", &JpsiTau_mu1_pt );
    tree_->Branch("JpsiTau_mu1_eta", &JpsiTau_mu1_eta );
    tree_->Branch("JpsiTau_mu1_phi", &JpsiTau_mu1_phi );
    tree_->Branch("JpsiTau_mu1_mass", &JpsiTau_mu1_mass );
    tree_->Branch("JpsiTau_mu1_q", &JpsiTau_mu1_q );
    tree_->Branch("JpsiTau_mu1_isLoose"  , &JpsiTau_mu1_isLoose   );
    tree_->Branch("JpsiTau_mu1_isTight"  , &JpsiTau_mu1_isTight   );
    tree_->Branch("JpsiTau_mu1_isPF"     , &JpsiTau_mu1_isPF      );
    tree_->Branch("JpsiTau_mu1_isGlobal" , &JpsiTau_mu1_isGlobal  );
    tree_->Branch("JpsiTau_mu1_isTracker", &JpsiTau_mu1_isTracker );
    tree_->Branch("JpsiTau_mu1_isSoft"   , &JpsiTau_mu1_isSoft    );
    tree_->Branch("JpsiTau_mu1_vx"   , &JpsiTau_mu1_vx    );
    tree_->Branch("JpsiTau_mu1_vy"   , &JpsiTau_mu1_vy    );
    tree_->Branch("JpsiTau_mu1_vz"   , &JpsiTau_mu1_vz    );
    tree_->Branch("JpsiTau_mu1_iso"   , &JpsiTau_mu1_iso    );
    tree_->Branch("JpsiTau_mu1_dbiso"   , &JpsiTau_mu1_dbiso    );

    tree_->Branch("JpsiTau_mu2_pt", &JpsiTau_mu2_pt );
    tree_->Branch("JpsiTau_mu2_eta", &JpsiTau_mu2_eta );
    tree_->Branch("JpsiTau_mu2_phi", &JpsiTau_mu2_phi );
    tree_->Branch("JpsiTau_mu2_mass", &JpsiTau_mu2_mass );
    tree_->Branch("JpsiTau_mu2_q", &JpsiTau_mu2_q );
    tree_->Branch("JpsiTau_mu2_isLoose"  , &JpsiTau_mu2_isLoose   );
    tree_->Branch("JpsiTau_mu2_isTight"  , &JpsiTau_mu2_isTight   );
    tree_->Branch("JpsiTau_mu2_isPF"     , &JpsiTau_mu2_isPF      );
    tree_->Branch("JpsiTau_mu2_isGlobal" , &JpsiTau_mu2_isGlobal  );
    tree_->Branch("JpsiTau_mu2_isTracker", &JpsiTau_mu2_isTracker );
    tree_->Branch("JpsiTau_mu2_isSoft"   , &JpsiTau_mu2_isSoft    );
    tree_->Branch("JpsiTau_mu2_vx"   , &JpsiTau_mu2_vx    );
    tree_->Branch("JpsiTau_mu2_vy"   , &JpsiTau_mu2_vy    );
    tree_->Branch("JpsiTau_mu2_vz"   , &JpsiTau_mu2_vz    );
    tree_->Branch("JpsiTau_mu2_iso"   , &JpsiTau_mu2_iso    );
    tree_->Branch("JpsiTau_mu2_dbiso"   , &JpsiTau_mu2_dbiso    );

    //    tree_->Branch("JpsiTau_tau_fullfit_pt", &JpsiTau_tau_fullfit_pt );
    //    tree_->Branch("JpsiTau_tau_fullfit_eta", &JpsiTau_tau_fullfit_eta );
    //    tree_->Branch("JpsiTau_tau_fullfit_phi", &JpsiTau_tau_fullfit_phi );
    //    tree_->Branch("JpsiTau_tau_fullfit_mass", &JpsiTau_tau_fullfit_mass );
    tree_->Branch("JpsiTau_tau_pt", &JpsiTau_tau_pt );
    tree_->Branch("JpsiTau_tau_eta", &JpsiTau_tau_eta );
    tree_->Branch("JpsiTau_tau_phi", &JpsiTau_tau_phi );
    tree_->Branch("JpsiTau_tau_mass", &JpsiTau_tau_mass );
    tree_->Branch("JpsiTau_tau_q", &JpsiTau_tau_q );
    tree_->Branch("JpsiTau_tau_vx"   , &JpsiTau_tau_vx    );
    tree_->Branch("JpsiTau_tau_vy"   , &JpsiTau_tau_vy    );
    tree_->Branch("JpsiTau_tau_vz"   , &JpsiTau_tau_vz    );

    tree_->Branch("JpsiTau_tau_max_dr_3prong", &JpsiTau_tau_max_dr_3prong);
    tree_->Branch("JpsiTau_tau_lip", &JpsiTau_tau_lip);
    tree_->Branch("JpsiTau_tau_lips", &JpsiTau_tau_lips);
    tree_->Branch("JpsiTau_tau_pvip", &JpsiTau_tau_pvip);
    tree_->Branch("JpsiTau_tau_pvips", &JpsiTau_tau_pvips);
    tree_->Branch("JpsiTau_tau_fl3d", &JpsiTau_tau_fl3d);
    tree_->Branch("JpsiTau_tau_fls3d", &JpsiTau_tau_fls3d);
    tree_->Branch("JpsiTau_tau_alpha", &JpsiTau_tau_alpha);
    tree_->Branch("JpsiTau_tau_vprob", &JpsiTau_tau_vprob);
    tree_->Branch("JpsiTau_tau_isRight", &JpsiTau_tau_isRight);
    tree_->Branch("JpsiTau_tau_isRight1", &JpsiTau_tau_isRight1);
    tree_->Branch("JpsiTau_tau_isRight2", &JpsiTau_tau_isRight2);
    tree_->Branch("JpsiTau_tau_isRight3", &JpsiTau_tau_isRight3);
    tree_->Branch("JpsiTau_tau_dr1", &JpsiTau_tau_dr1);
    tree_->Branch("JpsiTau_tau_dr2", &JpsiTau_tau_dr2);
    tree_->Branch("JpsiTau_tau_dr3", &JpsiTau_tau_dr3);
    tree_->Branch("JpsiTau_tau_ptres1", &JpsiTau_tau_ptres1);
    tree_->Branch("JpsiTau_tau_ptres2", &JpsiTau_tau_ptres2);
    tree_->Branch("JpsiTau_tau_ptres3", &JpsiTau_tau_ptres3);
    tree_->Branch("JpsiTau_tau_matched_ppdgId", &JpsiTau_tau_matched_ppdgId);
    tree_->Branch("JpsiTau_tau_matched_gentaupt", &JpsiTau_tau_matched_gentaupt);
    //    tree_->Branch("JpsiTau_tau_gentaupt", &JpsiTau_tau_gentaupt);
    tree_->Branch("JpsiTau_tau_sumofdnn", &JpsiTau_tau_sumofdnn);
    tree_->Branch("JpsiTau_tau_pfidx1", &JpsiTau_tau_pfidx1);
    tree_->Branch("JpsiTau_tau_pfidx2", &JpsiTau_tau_pfidx2);
    tree_->Branch("JpsiTau_tau_pfidx3", &JpsiTau_tau_pfidx3);
    tree_->Branch("JpsiTau_tau_pi1_dnn", &JpsiTau_tau_pi1_dnn );
    tree_->Branch("JpsiTau_tau_pi2_dnn", &JpsiTau_tau_pi2_dnn );
    tree_->Branch("JpsiTau_tau_pi3_dnn", &JpsiTau_tau_pi3_dnn );

    tree_->Branch("JpsiTau_tau_rhomass1", &JpsiTau_tau_rhomass1 );
    tree_->Branch("JpsiTau_tau_rhomass2", &JpsiTau_tau_rhomass2 );

    tree_->Branch("JpsiTau_tau_pi1_pt", &JpsiTau_tau_pi1_pt );
    tree_->Branch("JpsiTau_tau_pi1_eta", &JpsiTau_tau_pi1_eta );
    tree_->Branch("JpsiTau_tau_pi1_phi", &JpsiTau_tau_pi1_phi );
    tree_->Branch("JpsiTau_tau_pi1_mass", &JpsiTau_tau_pi1_mass );
    tree_->Branch("JpsiTau_tau_pi1_q", &JpsiTau_tau_pi1_q );

    tree_->Branch("JpsiTau_tau_pi2_pt", &JpsiTau_tau_pi2_pt );
    tree_->Branch("JpsiTau_tau_pi2_eta", &JpsiTau_tau_pi2_eta );
    tree_->Branch("JpsiTau_tau_pi2_phi", &JpsiTau_tau_pi2_phi );
    tree_->Branch("JpsiTau_tau_pi2_mass", &JpsiTau_tau_pi2_mass );
    tree_->Branch("JpsiTau_tau_pi2_q", &JpsiTau_tau_pi2_q );

    tree_->Branch("JpsiTau_tau_pi3_pt", &JpsiTau_tau_pi3_pt );
    tree_->Branch("JpsiTau_tau_pi3_eta", &JpsiTau_tau_pi3_eta );
    tree_->Branch("JpsiTau_tau_pi3_phi", &JpsiTau_tau_pi3_phi );
    tree_->Branch("JpsiTau_tau_pi3_mass", &JpsiTau_tau_pi3_mass );
    tree_->Branch("JpsiTau_tau_pi3_q", &JpsiTau_tau_pi3_q );


    tree_->Branch("JpsiTau_PV_vx", &JpsiTau_PV_vx );
    tree_->Branch("JpsiTau_PV_vy", &JpsiTau_PV_vy );
    tree_->Branch("JpsiTau_PV_vz", &JpsiTau_PV_vz );

    tree_->Branch("JpsiTau_bbPV_vx", &JpsiTau_bbPV_vx );
    tree_->Branch("JpsiTau_bbPV_vy", &JpsiTau_bbPV_vy );
    tree_->Branch("JpsiTau_bbPV_vz", &JpsiTau_bbPV_vz );

    tree_->Branch("JpsiTau_bbPV_refit_vx", &JpsiTau_bbPV_vx );
    tree_->Branch("JpsiTau_bbPV_refit_vy", &JpsiTau_bbPV_vy );
    tree_->Branch("JpsiTau_bbPV_refit_vz", &JpsiTau_bbPV_vz );

    tree_->Branch("JpsiTau_genPV_vx", &JpsiTau_genPV_vx );
    tree_->Branch("JpsiTau_genPV_vy", &JpsiTau_genPV_vy );
    tree_->Branch("JpsiTau_genPV_vz", &JpsiTau_genPV_vz );

    tree_->Branch("JpsiTau_Jpsi_pt", &JpsiTau_Jpsi_pt );
    tree_->Branch("JpsiTau_Jpsi_eta", &JpsiTau_Jpsi_eta );
    tree_->Branch("JpsiTau_Jpsi_phi", &JpsiTau_Jpsi_phi );
    tree_->Branch("JpsiTau_Jpsi_mass", &JpsiTau_Jpsi_mass );
    tree_->Branch("JpsiTau_Jpsi_vprob", &JpsiTau_Jpsi_vprob );
    tree_->Branch("JpsiTau_Jpsi_lip", &JpsiTau_Jpsi_lip);
    tree_->Branch("JpsiTau_Jpsi_lips", &JpsiTau_Jpsi_lips);
    tree_->Branch("JpsiTau_Jpsi_pvip", &JpsiTau_Jpsi_pvip);
    tree_->Branch("JpsiTau_Jpsi_pvips", &JpsiTau_Jpsi_pvips);
    tree_->Branch("JpsiTau_Jpsi_fl3d", &JpsiTau_Jpsi_fl3d);
    tree_->Branch("JpsiTau_Jpsi_fls3d", &JpsiTau_Jpsi_fls3d);
    tree_->Branch("JpsiTau_Jpsi_alpha", &JpsiTau_Jpsi_alpha);
    tree_->Branch("JpsiTau_Jpsi_maxdoca", &JpsiTau_Jpsi_maxdoca);
    tree_->Branch("JpsiTau_Jpsi_mindoca", &JpsiTau_Jpsi_mindoca);
    tree_->Branch("JpsiTau_Jpsi_vx", &JpsiTau_Jpsi_vx );
    tree_->Branch("JpsiTau_Jpsi_vy", &JpsiTau_Jpsi_vy );
    tree_->Branch("JpsiTau_Jpsi_vz", &JpsiTau_Jpsi_vz );
    tree_->Branch("JpsiTau_Jpsi_unfit_pt", &JpsiTau_Jpsi_unfit_pt );
    tree_->Branch("JpsiTau_Jpsi_unfit_mass", &JpsiTau_Jpsi_unfit_mass );
    tree_->Branch("JpsiTau_Jpsi_unfit_vprob", &JpsiTau_Jpsi_unfit_vprob );
    tree_->Branch("JpsiTau_Jpsi_unfit_vx", &JpsiTau_Jpsi_unfit_vx );
    tree_->Branch("JpsiTau_Jpsi_unfit_vy", &JpsiTau_Jpsi_unfit_vy );
    tree_->Branch("JpsiTau_Jpsi_unfit_vz", &JpsiTau_Jpsi_unfit_vz );


    tree_->Branch("JpsiTau_B_pt", &JpsiTau_B_pt );
    tree_->Branch("JpsiTau_B_eta", &JpsiTau_B_eta );
    tree_->Branch("JpsiTau_B_phi", &JpsiTau_B_phi );
    tree_->Branch("JpsiTau_B_mass", &JpsiTau_B_mass );
    tree_->Branch("JpsiTau_B_vprob", &JpsiTau_B_vprob );
    tree_->Branch("JpsiTau_B_lip", &JpsiTau_B_lip);
    tree_->Branch("JpsiTau_B_lips", &JpsiTau_B_lips);
    tree_->Branch("JpsiTau_B_pvip", &JpsiTau_B_pvip);
    tree_->Branch("JpsiTau_B_pvips", &JpsiTau_B_pvips);
    tree_->Branch("JpsiTau_B_fl3d", &JpsiTau_B_fl3d);
    tree_->Branch("JpsiTau_B_fls3d", &JpsiTau_B_fls3d);
    tree_->Branch("JpsiTau_B_alpha", &JpsiTau_B_alpha);
    tree_->Branch("JpsiTau_B_maxdoca", &JpsiTau_B_maxdoca);
    tree_->Branch("JpsiTau_B_mindoca", &JpsiTau_B_mindoca);
    tree_->Branch("JpsiTau_B_vx", &JpsiTau_B_vx );
    tree_->Branch("JpsiTau_B_vy", &JpsiTau_B_vy );
    tree_->Branch("JpsiTau_B_vz", &JpsiTau_B_vz );
    tree_->Branch("JpsiTau_B_iso", &JpsiTau_B_iso);
    tree_->Branch("JpsiTau_B_iso_ntracks", &JpsiTau_B_iso_ntracks );
    tree_->Branch("JpsiTau_B_iso_mindoca", &JpsiTau_B_iso_mindoca );

    tree_->Branch("JpsiTau_ngenmuons", &JpsiTau_ngenmuons);
    tree_->Branch("JpsiTau_isgenmatched", &JpsiTau_isgenmatched);
    tree_->Branch("JpsiTau_isgen3", &JpsiTau_isgen3);
    tree_->Branch("JpsiTau_isgen3matched", &JpsiTau_isgen3matched);
    tree_->Branch("JpsiTau_nch", &JpsiTau_nch);
    tree_->Branch("JpsiTau_nch_after_dnn", &JpsiTau_nch_after_dnn);
    tree_->Branch("JpsiTau_nch_before_dnn", &JpsiTau_nch_before_dnn);
    tree_->Branch("JpsiTau_nch_qr", &JpsiTau_nch_qr);
    tree_->Branch("JpsiTau_ngentau3", &JpsiTau_ngentau3); 
    tree_->Branch("JpsiTau_ngentau", &JpsiTau_ngentau);
    tree_->Branch("JpsiTau_gentaupt", &JpsiTau_gentaupt);
    tree_->Branch("JpsiTau_gentaudm", &JpsiTau_gentaudm);

  }



  if (runFlags["doBsTauTau"]){
    //tree_->Branch("TriggerName", &TriggerName ); //change
    tree_->Branch("IsBsTauTau", &IsBsTauTau );

    tree_->Branch("BsTauTau_nCandidates", &BsTauTau_nCandidates );

    tree_->Branch("BsTauTau_mu1_pt", &BsTauTau_mu1_pt );
    tree_->Branch("BsTauTau_mu1_eta", &BsTauTau_mu1_eta );
    tree_->Branch("BsTauTau_mu1_phi", &BsTauTau_mu1_phi );
    tree_->Branch("BsTauTau_mu1_mass", &BsTauTau_mu1_mass );
    tree_->Branch("BsTauTau_mu1_q", &BsTauTau_mu1_q );
    tree_->Branch("BsTauTau_mu1_isLoose"  , &BsTauTau_mu1_isLoose   );
    tree_->Branch("BsTauTau_mu1_isTight"  , &BsTauTau_mu1_isTight   );
    tree_->Branch("BsTauTau_mu1_isPF"     , &BsTauTau_mu1_isPF      );
    tree_->Branch("BsTauTau_mu1_isGlobal" , &BsTauTau_mu1_isGlobal  );
    tree_->Branch("BsTauTau_mu1_isTracker", &BsTauTau_mu1_isTracker );
    tree_->Branch("BsTauTau_mu1_isSoft"   , &BsTauTau_mu1_isSoft    );
    tree_->Branch("BsTauTau_mu1_vx"   , &BsTauTau_mu1_vx    );
    tree_->Branch("BsTauTau_mu1_vy"   , &BsTauTau_mu1_vy    );
    tree_->Branch("BsTauTau_mu1_vz"   , &BsTauTau_mu1_vz    );
    tree_->Branch("BsTauTau_mu1_iso"   , &BsTauTau_mu1_iso    );
    tree_->Branch("BsTauTau_mu1_dbiso"   , &BsTauTau_mu1_dbiso    );


    tree_->Branch("BsTauTau_tau_pt", &BsTauTau_tau_pt );
    tree_->Branch("BsTauTau_tau_eta", &BsTauTau_tau_eta );
    tree_->Branch("BsTauTau_tau_phi", &BsTauTau_tau_phi );
    tree_->Branch("BsTauTau_tau_mass", &BsTauTau_tau_mass );
    tree_->Branch("BsTauTau_tau_rhomass1", &BsTauTau_tau_rhomass1 );
    tree_->Branch("BsTauTau_tau_rhomass2", &BsTauTau_tau_rhomass2 );
    tree_->Branch("BsTauTau_tau_q", &BsTauTau_tau_q );
    tree_->Branch("BsTauTau_tau_vx"   , &BsTauTau_tau_vx    );
    tree_->Branch("BsTauTau_tau_vy"   , &BsTauTau_tau_vy    );
    tree_->Branch("BsTauTau_tau_vz"   , &BsTauTau_tau_vz    );

    tree_->Branch("BsTauTau_tau_max_dr_3prong", &BsTauTau_tau_max_dr_3prong);
    tree_->Branch("BsTauTau_tau_lip", &BsTauTau_tau_lip);
    tree_->Branch("BsTauTau_tau_lips", &BsTauTau_tau_lips);
    tree_->Branch("BsTauTau_tau_pvip", &BsTauTau_tau_pvip);
    tree_->Branch("BsTauTau_tau_pvips", &BsTauTau_tau_pvips);
    tree_->Branch("BsTauTau_tau_fl3d", &BsTauTau_tau_fl3d);
    tree_->Branch("BsTauTau_tau_fls3d", &BsTauTau_tau_fls3d);
    tree_->Branch("BsTauTau_tau_alpha", &BsTauTau_tau_alpha);
    tree_->Branch("BsTauTau_tau_vprob", &BsTauTau_tau_vprob);
    tree_->Branch("BsTauTau_tau_isRight", &BsTauTau_tau_isRight);
    tree_->Branch("BsTauTau_tau_isRight1", &BsTauTau_tau_isRight1);
    tree_->Branch("BsTauTau_tau_isRight2", &BsTauTau_tau_isRight2);
    tree_->Branch("BsTauTau_tau_isRight3", &BsTauTau_tau_isRight3);
    tree_->Branch("BsTauTau_tau_dr1", &BsTauTau_tau_dr1);
    tree_->Branch("BsTauTau_tau_dr2", &BsTauTau_tau_dr2);
    tree_->Branch("BsTauTau_tau_dr3", &BsTauTau_tau_dr3);
    tree_->Branch("BsTauTau_tau_ptres1", &BsTauTau_tau_ptres1);
    tree_->Branch("BsTauTau_tau_ptres2", &BsTauTau_tau_ptres2);
    tree_->Branch("BsTauTau_tau_ptres3", &BsTauTau_tau_ptres3);
    tree_->Branch("BsTauTau_tau_matched_ppdgId", &BsTauTau_tau_matched_ppdgId);
    tree_->Branch("BsTauTau_tau_matched_gentaupt", &BsTauTau_tau_matched_gentaupt); // this was commented out
    tree_->Branch("BsTauTau_tau_gentaupt", &BsTauTau_gentaupt);  // change of name  BsTauTau_tau_gentaupt --> BsTauTau_gentaupt like in BsTauTauNtuplizer
    tree_->Branch("BsTauTau_tau_sumofdnn", &BsTauTau_tau_sumofdnn);
    tree_->Branch("BsTauTau_tau_pfidx1", &BsTauTau_tau_pfidx1);
    tree_->Branch("BsTauTau_tau_pfidx2", &BsTauTau_tau_pfidx2);
    tree_->Branch("BsTauTau_tau_pfidx3", &BsTauTau_tau_pfidx3);
    tree_->Branch("BsTauTau_tau_pi1_dnn", &BsTauTau_tau_pi1_dnn );
    tree_->Branch("BsTauTau_tau_pi2_dnn", &BsTauTau_tau_pi2_dnn );
    tree_->Branch("BsTauTau_tau_pi3_dnn", &BsTauTau_tau_pi3_dnn );

    tree_->Branch("BsTauTau_tau_pi1_pt", &BsTauTau_tau_pi1_pt );
    tree_->Branch("BsTauTau_tau_pi1_eta", &BsTauTau_tau_pi1_eta );
    tree_->Branch("BsTauTau_tau_pi1_phi", &BsTauTau_tau_pi1_phi );
    tree_->Branch("BsTauTau_tau_pi1_mass", &BsTauTau_tau_pi1_mass );  
    tree_->Branch("BsTauTau_tau_pi1_charge", &BsTauTau_tau_pi1_charge ); ;  // change
    tree_->Branch("BsTauTau_tau_pi1_dz", &BsTauTau_tau_pi1_dz ); ;  // change
    tree_->Branch("BsTauTau_tau_muon_dr1", &BsTauTau_tau_muon_dr1 ); ;  // change
    tree_->Branch("HLT_BPH_isFired", &HLT_BPH_isFired ); //change


    tree_->Branch("BsTauTau_tau_pi2_pt", &BsTauTau_tau_pi2_pt );
    tree_->Branch("BsTauTau_tau_pi2_eta", &BsTauTau_tau_pi2_eta );
    tree_->Branch("BsTauTau_tau_pi2_phi", &BsTauTau_tau_pi2_phi );
    tree_->Branch("BsTauTau_tau_pi2_mass", &BsTauTau_tau_pi2_mass );
    tree_->Branch("BsTauTau_tau_pi2_charge", &BsTauTau_tau_pi2_charge );
    tree_->Branch("BsTauTau_tau_pi2_dz", &BsTauTau_tau_pi2_dz ); ;  // change
    tree_->Branch("BsTauTau_tau_muon_dr2", &BsTauTau_tau_muon_dr2 ); ;  // change

    tree_->Branch("BsTauTau_tau_pi3_pt", &BsTauTau_tau_pi3_pt );
    tree_->Branch("BsTauTau_tau_pi3_eta", &BsTauTau_tau_pi3_eta );
    tree_->Branch("BsTauTau_tau_pi3_phi", &BsTauTau_tau_pi3_phi );
    tree_->Branch("BsTauTau_tau_pi3_mass", &BsTauTau_tau_pi3_mass );
    tree_->Branch("BsTauTau_tau_pi3_charge", &BsTauTau_tau_pi3_charge );
    tree_->Branch("BsTauTau_tau_pi3_dz", &BsTauTau_tau_pi3_dz ); ;  // change
    tree_->Branch("BsTauTau_tau_muon_dr3", &BsTauTau_tau_muon_dr3 ); ;  // change


    tree_->Branch("BsTauTau_PV_vx", &BsTauTau_PV_vx );
    tree_->Branch("BsTauTau_PV_vy", &BsTauTau_PV_vy );
    tree_->Branch("BsTauTau_PV_vz", &BsTauTau_PV_vz );

    tree_->Branch("BsTauTau_bbPV_vx", &BsTauTau_bbPV_vx );
    tree_->Branch("BsTauTau_bbPV_vy", &BsTauTau_bbPV_vy );
    tree_->Branch("BsTauTau_bbPV_vz", &BsTauTau_bbPV_vz );

    tree_->Branch("BsTauTau_bbPV_refit_vx", &BsTauTau_bbPV_vx );
    tree_->Branch("BsTauTau_bbPV_refit_vy", &BsTauTau_bbPV_vy );
    tree_->Branch("BsTauTau_bbPV_refit_vz", &BsTauTau_bbPV_vz );

    tree_->Branch("BsTauTau_genPV_vx", &BsTauTau_genPV_vx );
    tree_->Branch("BsTauTau_genPV_vy", &BsTauTau_genPV_vy );
    tree_->Branch("BsTauTau_genPV_vz", &BsTauTau_genPV_vz );

    tree_->Branch("BsTauTau_B_pt", &BsTauTau_B_pt );
    tree_->Branch("BsTauTau_B_eta", &BsTauTau_B_eta );
    tree_->Branch("BsTauTau_B_phi", &BsTauTau_B_phi );
    tree_->Branch("BsTauTau_B_mass", &BsTauTau_B_mass );
    tree_->Branch("BsTauTau_B_vprob", &BsTauTau_B_vprob );
    tree_->Branch("BsTauTau_B_lip", &BsTauTau_B_lip);
    tree_->Branch("BsTauTau_B_lips", &BsTauTau_B_lips);
    tree_->Branch("BsTauTau_B_pvip", &BsTauTau_B_pvip);
    tree_->Branch("BsTauTau_B_pvips", &BsTauTau_B_pvips);
    tree_->Branch("BsTauTau_B_fl3d", &BsTauTau_B_fl3d);
    tree_->Branch("BsTauTau_B_fls3d", &BsTauTau_B_fls3d);
    tree_->Branch("BsTauTau_B_alpha", &BsTauTau_B_alpha);
    tree_->Branch("BsTauTau_B_maxdoca", &BsTauTau_B_maxdoca);
    tree_->Branch("BsTauTau_B_mindoca", &BsTauTau_B_mindoca);
    tree_->Branch("BsTauTau_muonpion_maxdoca", &BsTauTau_muonpion_maxdoca);
    tree_->Branch("BsTauTau_muonpion_mindoca", &BsTauTau_muonpion_mindoca);
    tree_->Branch("BsTauTau_B_vx", &BsTauTau_B_vx );
    tree_->Branch("BsTauTau_B_vy", &BsTauTau_B_vy );
    tree_->Branch("BsTauTau_B_vz", &BsTauTau_B_vz );
    tree_->Branch("BsTauTau_B_iso", &BsTauTau_B_iso);
    tree_->Branch("BsTauTau_B_iso_ntracks", &BsTauTau_B_iso_ntracks );
    tree_->Branch("BsTauTau_B_iso_mindoca", &BsTauTau_B_iso_mindoca );

    tree_->Branch("BsTauTau_ngenmuons", &BsTauTau_ngenmuons);
    tree_->Branch("BsTauTau_isgen3", &BsTauTau_isgen3);
    tree_->Branch("BsTauTau_isgen3matched", &BsTauTau_isgen3matched);
    tree_->Branch("BsTauTau_nch", &BsTauTau_nch);
    tree_->Branch("BsTauTau_nch_after_dnn", &BsTauTau_nch_after_dnn);
    tree_->Branch("BsTauTau_nch_before_dnn", &BsTauTau_nch_before_dnn);
    tree_->Branch("BsTauTau_nch_qr", &BsTauTau_nch_qr);
    tree_->Branch("BsTauTau_ngentau3", &BsTauTau_ngentau3); 
    tree_->Branch("BsTauTau_ngentau", &BsTauTau_ngentau);
    tree_->Branch("BsTauTau_gentaupt", &BsTauTau_gentaupt);
    tree_->Branch("BsTauTau_gentaudm", &BsTauTau_gentaudm);

  }


  if (runFlags["doBsTauTauFH"]){
    tree_->Branch("IsBsTauTauFH", &IsBsTauTauFH );


    tree_->Branch("BsTauTauFH_nCandidates", &BsTauTauFH_nCandidates );
    tree_->Branch("BsTauTauFH_ntaus", &BsTauTauFH_ntaus );

    tree_->Branch("BsTauTauFH_mu1_pt", &BsTauTauFH_mu1_pt );
    tree_->Branch("BsTauTauFH_mu1_eta", &BsTauTauFH_mu1_eta );
    tree_->Branch("BsTauTauFH_mu1_phi", &BsTauTauFH_mu1_phi );
    tree_->Branch("BsTauTauFH_mu1_mass", &BsTauTauFH_mu1_mass );
    tree_->Branch("BsTauTauFH_mu1_q", &BsTauTauFH_mu1_q );
    tree_->Branch("BsTauTauFH_mu1_isLoose"  , &BsTauTauFH_mu1_isLoose   );
    tree_->Branch("BsTauTauFH_mu1_isTight"  , &BsTauTauFH_mu1_isTight   );
    tree_->Branch("BsTauTauFH_mu1_isPF"     , &BsTauTauFH_mu1_isPF      );
    tree_->Branch("BsTauTauFH_mu1_isGlobal" , &BsTauTauFH_mu1_isGlobal  );
    tree_->Branch("BsTauTauFH_mu1_isTracker", &BsTauTauFH_mu1_isTracker );
    tree_->Branch("BsTauTauFH_mu1_isSoft"   , &BsTauTauFH_mu1_isSoft    );
    tree_->Branch("BsTauTauFH_mu1_vx"   , &BsTauTauFH_mu1_vx    );
    tree_->Branch("BsTauTauFH_mu1_vy"   , &BsTauTauFH_mu1_vy    );
    tree_->Branch("BsTauTauFH_mu1_vz"   , &BsTauTauFH_mu1_vz    );
    tree_->Branch("BsTauTauFH_mu1_iso"   , &BsTauTauFH_mu1_iso    );
    tree_->Branch("BsTauTauFH_mu1_dbiso"   , &BsTauTauFH_mu1_dbiso    );


    tree_->Branch("BsTauTauFH_tau1_pt", &BsTauTauFH_tau1_pt );
    tree_->Branch("BsTauTauFH_tau1_eta", &BsTauTauFH_tau1_eta );
    tree_->Branch("BsTauTauFH_tau1_phi", &BsTauTauFH_tau1_phi );
    tree_->Branch("BsTauTauFH_tau1_mass", &BsTauTauFH_tau1_mass );
    tree_->Branch("BsTauTauFH_tau1_rhomass1", &BsTauTauFH_tau1_rhomass1 );
    tree_->Branch("BsTauTauFH_tau1_rhomass2", &BsTauTauFH_tau1_rhomass2 );
    tree_->Branch("BsTauTauFH_tau1_q", &BsTauTauFH_tau1_q );
    tree_->Branch("BsTauTauFH_tau1_vx"   , &BsTauTauFH_tau1_vx    );
    tree_->Branch("BsTauTauFH_tau1_vy"   , &BsTauTauFH_tau1_vy    );
    tree_->Branch("BsTauTauFH_tau1_vz"   , &BsTauTauFH_tau1_vz    );

    tree_->Branch("BsTauTauFH_tau1_max_dr_3prong", &BsTauTauFH_tau1_max_dr_3prong);
    tree_->Branch("BsTauTauFH_tau1_lip", &BsTauTauFH_tau1_lip);
    tree_->Branch("BsTauTauFH_tau1_lips", &BsTauTauFH_tau1_lips);
    tree_->Branch("BsTauTauFH_tau1_pvip", &BsTauTauFH_tau1_pvip);
    tree_->Branch("BsTauTauFH_tau1_pvips", &BsTauTauFH_tau1_pvips);
    tree_->Branch("BsTauTauFH_tau1_fl3d", &BsTauTauFH_tau1_fl3d);
    tree_->Branch("BsTauTauFH_tau1_fls3d", &BsTauTauFH_tau1_fls3d);
    tree_->Branch("BsTauTauFH_tau1_alpha", &BsTauTauFH_tau1_alpha);
    tree_->Branch("BsTauTauFH_tau1_vprob", &BsTauTauFH_tau1_vprob);
    tree_->Branch("BsTauTauFH_tau1_isRight", &BsTauTauFH_tau1_isRight);
    tree_->Branch("BsTauTauFH_tau1_matched_ppdgId", &BsTauTauFH_tau1_matched_ppdgId);
    tree_->Branch("BsTauTauFH_tau1_matched_gentaupt", &BsTauTauFH_tau1_matched_gentaupt);
    //    tree_->Branch("BsTauTauFH_tau1_gentaupt", &BsTauTauFH_tau1_gentaupt);
    tree_->Branch("BsTauTauFH_tau1_sumofdnn", &BsTauTauFH_tau1_sumofdnn);
    tree_->Branch("BsTauTauFH_tau1_pfidx1", &BsTauTauFH_tau1_pfidx1);
    tree_->Branch("BsTauTauFH_tau1_pfidx2", &BsTauTauFH_tau1_pfidx2);
    tree_->Branch("BsTauTauFH_tau1_pfidx3", &BsTauTauFH_tau1_pfidx3);
    tree_->Branch("BsTauTauFH_tau1_pi1_dnn", &BsTauTauFH_tau1_pi1_dnn );
    tree_->Branch("BsTauTauFH_tau1_pi2_dnn", &BsTauTauFH_tau1_pi2_dnn );
    tree_->Branch("BsTauTauFH_tau1_pi3_dnn", &BsTauTauFH_tau1_pi3_dnn );

    tree_->Branch("BsTauTauFH_tau1_pi1_pt", &BsTauTauFH_tau1_pi1_pt );
    tree_->Branch("BsTauTauFH_tau1_pi1_eta", &BsTauTauFH_tau1_pi1_eta );
    tree_->Branch("BsTauTauFH_tau1_pi1_phi", &BsTauTauFH_tau1_pi1_phi );
    tree_->Branch("BsTauTauFH_tau1_pi1_mass", &BsTauTauFH_tau1_pi1_mass );

    tree_->Branch("BsTauTauFH_tau1_pi2_pt", &BsTauTauFH_tau1_pi2_pt );
    tree_->Branch("BsTauTauFH_tau1_pi2_eta", &BsTauTauFH_tau1_pi2_eta );
    tree_->Branch("BsTauTauFH_tau1_pi2_phi", &BsTauTauFH_tau1_pi2_phi );
    tree_->Branch("BsTauTauFH_tau1_pi2_mass", &BsTauTauFH_tau1_pi2_mass );

    tree_->Branch("BsTauTauFH_tau1_pi3_pt", &BsTauTauFH_tau1_pi3_pt );
    tree_->Branch("BsTauTauFH_tau1_pi3_eta", &BsTauTauFH_tau1_pi3_eta );
    tree_->Branch("BsTauTauFH_tau1_pi3_phi", &BsTauTauFH_tau1_pi3_phi );
    tree_->Branch("BsTauTauFH_tau1_pi3_mass", &BsTauTauFH_tau1_pi3_mass );

    
    tree_->Branch("BsTauTauFH_tau2_pt", &BsTauTauFH_tau2_pt );
    tree_->Branch("BsTauTauFH_tau2_eta", &BsTauTauFH_tau2_eta );
    tree_->Branch("BsTauTauFH_tau2_phi", &BsTauTauFH_tau2_phi );
    tree_->Branch("BsTauTauFH_tau2_mass", &BsTauTauFH_tau2_mass );
    tree_->Branch("BsTauTauFH_tau2_rhomass1", &BsTauTauFH_tau2_rhomass1 );
    tree_->Branch("BsTauTauFH_tau2_rhomass2", &BsTauTauFH_tau2_rhomass2 );
    tree_->Branch("BsTauTauFH_tau2_q", &BsTauTauFH_tau2_q );
    tree_->Branch("BsTauTauFH_tau2_vx"   , &BsTauTauFH_tau2_vx    );
    tree_->Branch("BsTauTauFH_tau2_vy"   , &BsTauTauFH_tau2_vy    );
    tree_->Branch("BsTauTauFH_tau2_vz"   , &BsTauTauFH_tau2_vz    );

    tree_->Branch("BsTauTauFH_tau2_max_dr_3prong", &BsTauTauFH_tau2_max_dr_3prong);
    tree_->Branch("BsTauTauFH_tau2_lip", &BsTauTauFH_tau2_lip);
    tree_->Branch("BsTauTauFH_tau2_lips", &BsTauTauFH_tau2_lips);
    tree_->Branch("BsTauTauFH_tau2_pvip", &BsTauTauFH_tau2_pvip);
    tree_->Branch("BsTauTauFH_tau2_pvips", &BsTauTauFH_tau2_pvips);
    tree_->Branch("BsTauTauFH_tau2_fl3d", &BsTauTauFH_tau2_fl3d);
    tree_->Branch("BsTauTauFH_tau2_fls3d", &BsTauTauFH_tau2_fls3d);
    tree_->Branch("BsTauTauFH_tau2_alpha", &BsTauTauFH_tau2_alpha);
    tree_->Branch("BsTauTauFH_tau2_vprob", &BsTauTauFH_tau2_vprob);
    tree_->Branch("BsTauTauFH_tau2_isRight", &BsTauTauFH_tau2_isRight);
    tree_->Branch("BsTauTauFH_tau2_matched_ppdgId", &BsTauTauFH_tau2_matched_ppdgId);
    tree_->Branch("BsTauTauFH_tau2_matched_gentaupt", &BsTauTauFH_tau2_matched_gentaupt);
    //    tree_->Branch("BsTauTauFH_tau2_gentaupt", &BsTauTauFH_tau2_gentaupt);
    tree_->Branch("BsTauTauFH_tau2_sumofdnn", &BsTauTauFH_tau2_sumofdnn);
    tree_->Branch("BsTauTauFH_tau2_pfidx1", &BsTauTauFH_tau2_pfidx1);
    tree_->Branch("BsTauTauFH_tau2_pfidx2", &BsTauTauFH_tau2_pfidx2);
    tree_->Branch("BsTauTauFH_tau2_pfidx3", &BsTauTauFH_tau2_pfidx3);
    tree_->Branch("BsTauTauFH_tau2_pi1_dnn", &BsTauTauFH_tau2_pi1_dnn );
    tree_->Branch("BsTauTauFH_tau2_pi2_dnn", &BsTauTauFH_tau2_pi2_dnn );
    tree_->Branch("BsTauTauFH_tau2_pi3_dnn", &BsTauTauFH_tau2_pi3_dnn );

    tree_->Branch("BsTauTauFH_tau2_pi1_pt", &BsTauTauFH_tau2_pi1_pt );
    tree_->Branch("BsTauTauFH_tau2_pi1_eta", &BsTauTauFH_tau2_pi1_eta );
    tree_->Branch("BsTauTauFH_tau2_pi1_phi", &BsTauTauFH_tau2_pi1_phi );
    tree_->Branch("BsTauTauFH_tau2_pi1_mass", &BsTauTauFH_tau2_pi1_mass );

    tree_->Branch("BsTauTauFH_tau2_pi2_pt", &BsTauTauFH_tau2_pi2_pt );
    tree_->Branch("BsTauTauFH_tau2_pi2_eta", &BsTauTauFH_tau2_pi2_eta );
    tree_->Branch("BsTauTauFH_tau2_pi2_phi", &BsTauTauFH_tau2_pi2_phi );
    tree_->Branch("BsTauTauFH_tau2_pi2_mass", &BsTauTauFH_tau2_pi2_mass );

    tree_->Branch("BsTauTauFH_tau2_pi3_pt", &BsTauTauFH_tau2_pi3_pt );
    tree_->Branch("BsTauTauFH_tau2_pi3_eta", &BsTauTauFH_tau2_pi3_eta );
    tree_->Branch("BsTauTauFH_tau2_pi3_phi", &BsTauTauFH_tau2_pi3_phi );
    tree_->Branch("BsTauTauFH_tau2_pi3_mass", &BsTauTauFH_tau2_pi3_mass );


    tree_->Branch("BsTauTauFH_PV_vx", &BsTauTauFH_PV_vx );
    tree_->Branch("BsTauTauFH_PV_vy", &BsTauTauFH_PV_vy );
    tree_->Branch("BsTauTauFH_PV_vz", &BsTauTauFH_PV_vz );

    tree_->Branch("BsTauTauFH_bbPV_vx", &BsTauTauFH_bbPV_vx );
    tree_->Branch("BsTauTauFH_bbPV_vy", &BsTauTauFH_bbPV_vy );
    tree_->Branch("BsTauTauFH_bbPV_vz", &BsTauTauFH_bbPV_vz );

    tree_->Branch("BsTauTauFH_bbPV_refit_vx", &BsTauTauFH_bbPV_vx );
    tree_->Branch("BsTauTauFH_bbPV_refit_vy", &BsTauTauFH_bbPV_vy );
    tree_->Branch("BsTauTauFH_bbPV_refit_vz", &BsTauTauFH_bbPV_vz );

    tree_->Branch("BsTauTauFH_genPV_vx", &BsTauTauFH_genPV_vx );
    tree_->Branch("BsTauTauFH_genPV_vy", &BsTauTauFH_genPV_vy );
    tree_->Branch("BsTauTauFH_genPV_vz", &BsTauTauFH_genPV_vz );

    tree_->Branch("BsTauTauFH_B_pt", &BsTauTauFH_B_pt );
    tree_->Branch("BsTauTauFH_B_eta", &BsTauTauFH_B_eta );
    tree_->Branch("BsTauTauFH_B_phi", &BsTauTauFH_B_phi );
    tree_->Branch("BsTauTauFH_B_mass", &BsTauTauFH_B_mass );
    tree_->Branch("BsTauTauFH_B_vprob", &BsTauTauFH_B_vprob );
    tree_->Branch("BsTauTauFH_B_lip", &BsTauTauFH_B_lip);
    tree_->Branch("BsTauTauFH_B_lips", &BsTauTauFH_B_lips);
    tree_->Branch("BsTauTauFH_B_pvip", &BsTauTauFH_B_pvip);
    tree_->Branch("BsTauTauFH_B_pvips", &BsTauTauFH_B_pvips);
    tree_->Branch("BsTauTauFH_B_fl3d", &BsTauTauFH_B_fl3d);
    tree_->Branch("BsTauTauFH_B_fls3d", &BsTauTauFH_B_fls3d);
    tree_->Branch("BsTauTauFH_B_alpha", &BsTauTauFH_B_alpha);
    tree_->Branch("BsTauTauFH_B_maxdoca", &BsTauTauFH_B_maxdoca);
    tree_->Branch("BsTauTauFH_B_mindoca", &BsTauTauFH_B_mindoca);
    tree_->Branch("BsTauTauFH_B_vx", &BsTauTauFH_B_vx );
    tree_->Branch("BsTauTauFH_B_vy", &BsTauTauFH_B_vy );
    tree_->Branch("BsTauTauFH_B_vz", &BsTauTauFH_B_vz );
    tree_->Branch("BsTauTauFH_B_iso", &BsTauTauFH_B_iso);
    tree_->Branch("BsTauTauFH_B_iso_ntracks", &BsTauTauFH_B_iso_ntracks );
    tree_->Branch("BsTauTauFH_B_iso_mindoca", &BsTauTauFH_B_iso_mindoca );

    tree_->Branch("BsTauTauFH_ngenmuons", &BsTauTauFH_ngenmuons);
    tree_->Branch("BsTauTauFH_isgen3", &BsTauTauFH_isgen3);
    tree_->Branch("BsTauTauFH_isgen3matched", &BsTauTauFH_isgen3matched);
    tree_->Branch("BsTauTauFH_nch", &BsTauTauFH_nch);
    tree_->Branch("BsTauTauFH_nch_after_dnn", &BsTauTauFH_nch_after_dnn);
    tree_->Branch("BsTauTauFH_nch_before_dnn", &BsTauTauFH_nch_before_dnn);
    tree_->Branch("BsTauTauFH_nch_qr", &BsTauTauFH_nch_qr);
    tree_->Branch("BsTauTauFH_ngentau3", &BsTauTauFH_ngentau3); 
    tree_->Branch("BsTauTauFH_ngentau", &BsTauTauFH_ngentau);
    tree_->Branch("BsTauTauFH_gentaupt", &BsTauTauFH_gentaupt);
    tree_->Branch("BsTauTauFH_gentaudm", &BsTauTauFH_gentaudm);

  }

  if (runFlags["doBsDstarTauNu"]){

    tree_->Branch("IsBsDstarTauNu", &IsBsDstarTauNu );

    tree_->Branch("BsDstarTauNu_nCandidates", &BsDstarTauNu_nCandidates );

    tree_->Branch("BsDstarTauNu_mu1_pt", &BsDstarTauNu_mu1_pt );
    tree_->Branch("BsDstarTauNu_mu1_eta", &BsDstarTauNu_mu1_eta );
    tree_->Branch("BsDstarTauNu_mu1_phi", &BsDstarTauNu_mu1_phi );
    tree_->Branch("BsDstarTauNu_mu1_mass", &BsDstarTauNu_mu1_mass );
    tree_->Branch("BsDstarTauNu_mu1_q", &BsDstarTauNu_mu1_q );
    tree_->Branch("BsDstarTauNu_mu1_isLoose"  , &BsDstarTauNu_mu1_isLoose   );
    tree_->Branch("BsDstarTauNu_mu1_isTight"  , &BsDstarTauNu_mu1_isTight   );
    tree_->Branch("BsDstarTauNu_mu1_isPF"     , &BsDstarTauNu_mu1_isPF      );
    tree_->Branch("BsDstarTauNu_mu1_isGlobal" , &BsDstarTauNu_mu1_isGlobal  );
    tree_->Branch("BsDstarTauNu_mu1_isTracker", &BsDstarTauNu_mu1_isTracker );
    tree_->Branch("BsDstarTauNu_mu1_isSoft"   , &BsDstarTauNu_mu1_isSoft    );
    tree_->Branch("BsDstarTauNu_mu1_vx"   , &BsDstarTauNu_mu1_vx    );
    tree_->Branch("BsDstarTauNu_mu1_vy"   , &BsDstarTauNu_mu1_vy    );
    tree_->Branch("BsDstarTauNu_mu1_vz"   , &BsDstarTauNu_mu1_vz    );
    tree_->Branch("BsDstarTauNu_mu1_iso"   , &BsDstarTauNu_mu1_iso    );
    tree_->Branch("BsDstarTauNu_mu1_dbiso"   , &BsDstarTauNu_mu1_dbiso    );


    tree_->Branch("BsDstarTauNu_tau_fullfit_pt", &BsDstarTauNu_tau_fullfit_pt );
    tree_->Branch("BsDstarTauNu_tau_fullfit_eta", &BsDstarTauNu_tau_fullfit_eta );
    tree_->Branch("BsDstarTauNu_tau_fullfit_phi", &BsDstarTauNu_tau_fullfit_phi );
    tree_->Branch("BsDstarTauNu_tau_fullfit_mass", &BsDstarTauNu_tau_fullfit_mass );
    tree_->Branch("BsDstarTauNu_tau_pt", &BsDstarTauNu_tau_pt );
    tree_->Branch("BsDstarTauNu_tau_eta", &BsDstarTauNu_tau_eta );
    tree_->Branch("BsDstarTauNu_tau_phi", &BsDstarTauNu_tau_phi );
    tree_->Branch("BsDstarTauNu_tau_mass", &BsDstarTauNu_tau_mass );
    tree_->Branch("BsDstarTauNu_tau_rhomass1", &BsDstarTauNu_tau_rhomass1 );
    tree_->Branch("BsDstarTauNu_tau_rhomass2", &BsDstarTauNu_tau_rhomass2 );
    tree_->Branch("BsDstarTauNu_tau_q", &BsDstarTauNu_tau_q );
    tree_->Branch("BsDstarTauNu_tau_vx"   , &BsDstarTauNu_tau_vx    );
    tree_->Branch("BsDstarTauNu_tau_vy"   , &BsDstarTauNu_tau_vy    );
    tree_->Branch("BsDstarTauNu_tau_vz"   , &BsDstarTauNu_tau_vz    );

    tree_->Branch("BsDstarTauNu_tau_max_dr_3prong", &BsDstarTauNu_tau_max_dr_3prong);
    tree_->Branch("BsDstarTauNu_tau_lip", &BsDstarTauNu_tau_lip);
    tree_->Branch("BsDstarTauNu_tau_lips", &BsDstarTauNu_tau_lips);
    tree_->Branch("BsDstarTauNu_tau_pvip", &BsDstarTauNu_tau_pvip);
    tree_->Branch("BsDstarTauNu_tau_pvips", &BsDstarTauNu_tau_pvips);
    tree_->Branch("BsDstarTauNu_tau_fl3d", &BsDstarTauNu_tau_fl3d);
    tree_->Branch("BsDstarTauNu_tau_fls3d", &BsDstarTauNu_tau_fls3d);
    tree_->Branch("BsDstarTauNu_tau_alpha", &BsDstarTauNu_tau_alpha);
    tree_->Branch("BsDstarTauNu_tau_vprob", &BsDstarTauNu_tau_vprob);
    tree_->Branch("BsDstarTauNu_tau_isRight", &BsDstarTauNu_tau_isRight);
    tree_->Branch("BsDstarTauNu_tau_matched_ppdgId", &BsDstarTauNu_tau_matched_ppdgId);
    tree_->Branch("BsDstarTauNu_tau_matched_gentaupt", &BsDstarTauNu_tau_matched_gentaupt);
    //    tree_->Branch("BsDstarTauNu_tau_gentaupt", &BsDstarTauNu_tau_gentaupt);
    tree_->Branch("BsDstarTauNu_tau_sumofdnn", &BsDstarTauNu_tau_sumofdnn);
    tree_->Branch("BsDstarTauNu_tau_pfidx1", &BsDstarTauNu_tau_pfidx1);
    tree_->Branch("BsDstarTauNu_tau_pfidx2", &BsDstarTauNu_tau_pfidx2);
    tree_->Branch("BsDstarTauNu_tau_pfidx3", &BsDstarTauNu_tau_pfidx3);

    tree_->Branch("BsDstarTauNu_tau_pi1_pt", &BsDstarTauNu_tau_pi1_pt );
    tree_->Branch("BsDstarTauNu_tau_pi1_eta", &BsDstarTauNu_tau_pi1_eta );
    tree_->Branch("BsDstarTauNu_tau_pi1_phi", &BsDstarTauNu_tau_pi1_phi );
    tree_->Branch("BsDstarTauNu_tau_pi1_mass", &BsDstarTauNu_tau_pi1_mass );

    tree_->Branch("BsDstarTauNu_tau_pi2_pt", &BsDstarTauNu_tau_pi2_pt );
    tree_->Branch("BsDstarTauNu_tau_pi2_eta", &BsDstarTauNu_tau_pi2_eta );
    tree_->Branch("BsDstarTauNu_tau_pi2_phi", &BsDstarTauNu_tau_pi2_phi );
    tree_->Branch("BsDstarTauNu_tau_pi2_mass", &BsDstarTauNu_tau_pi2_mass );

    tree_->Branch("BsDstarTauNu_tau_pi3_pt", &BsDstarTauNu_tau_pi3_pt );
    tree_->Branch("BsDstarTauNu_tau_pi3_eta", &BsDstarTauNu_tau_pi3_eta );
    tree_->Branch("BsDstarTauNu_tau_pi3_phi", &BsDstarTauNu_tau_pi3_phi );
    tree_->Branch("BsDstarTauNu_tau_pi3_mass", &BsDstarTauNu_tau_pi3_mass );


    tree_->Branch("BsDstarTauNu_PV_vx", &BsDstarTauNu_PV_vx );
    tree_->Branch("BsDstarTauNu_PV_vy", &BsDstarTauNu_PV_vy );
    tree_->Branch("BsDstarTauNu_PV_vz", &BsDstarTauNu_PV_vz );

    tree_->Branch("BsDstarTauNu_bbPV_vx", &BsDstarTauNu_bbPV_vx );
    tree_->Branch("BsDstarTauNu_bbPV_vy", &BsDstarTauNu_bbPV_vy );
    tree_->Branch("BsDstarTauNu_bbPV_vz", &BsDstarTauNu_bbPV_vz );

    tree_->Branch("BsDstarTauNu_bbPV_refit_vx", &BsDstarTauNu_bbPV_vx );
    tree_->Branch("BsDstarTauNu_bbPV_refit_vy", &BsDstarTauNu_bbPV_vy );
    tree_->Branch("BsDstarTauNu_bbPV_refit_vz", &BsDstarTauNu_bbPV_vz );

    tree_->Branch("BsDstarTauNu_genPV_vx", &BsDstarTauNu_genPV_vx );
    tree_->Branch("BsDstarTauNu_genPV_vy", &BsDstarTauNu_genPV_vy );
    tree_->Branch("BsDstarTauNu_genPV_vz", &BsDstarTauNu_genPV_vz );

    tree_->Branch("BsDstarTauNu_Ds_pt", &BsDstarTauNu_Ds_pt );
    tree_->Branch("BsDstarTauNu_Ds_eta", &BsDstarTauNu_Ds_eta );
    tree_->Branch("BsDstarTauNu_Ds_phi", &BsDstarTauNu_Ds_phi );
    tree_->Branch("BsDstarTauNu_Ds_mass", &BsDstarTauNu_Ds_mass );
    tree_->Branch("BsDstarTauNu_Ds_vprob", &BsDstarTauNu_Ds_vprob );
    tree_->Branch("BsDstarTauNu_Ds_lip", &BsDstarTauNu_Ds_lip);
    tree_->Branch("BsDstarTauNu_Ds_lips", &BsDstarTauNu_Ds_lips);
    tree_->Branch("BsDstarTauNu_Ds_pvip", &BsDstarTauNu_Ds_pvip);
    tree_->Branch("BsDstarTauNu_Ds_pvips", &BsDstarTauNu_Ds_pvips);
    tree_->Branch("BsDstarTauNu_Ds_fl3d", &BsDstarTauNu_Ds_fl3d);
    tree_->Branch("BsDstarTauNu_Ds_fls3d", &BsDstarTauNu_Ds_fls3d);
    tree_->Branch("BsDstarTauNu_Ds_alpha", &BsDstarTauNu_Ds_alpha);
    tree_->Branch("BsDstarTauNu_Ds_vx", &BsDstarTauNu_Ds_vx );
    tree_->Branch("BsDstarTauNu_Ds_vy", &BsDstarTauNu_Ds_vy );
    tree_->Branch("BsDstarTauNu_Ds_vz", &BsDstarTauNu_Ds_vz );
    tree_->Branch("BsDstarTauNu_Ds_unfit_pt", &BsDstarTauNu_Ds_unfit_pt );
    tree_->Branch("BsDstarTauNu_Ds_unfit_mass", &BsDstarTauNu_Ds_unfit_mass );
    tree_->Branch("BsDstarTauNu_Ds_ptfrac", &BsDstarTauNu_Ds_ptfrac );

    tree_->Branch("BsDstarTauNu_D0_pt", &BsDstarTauNu_D0_pt );
    tree_->Branch("BsDstarTauNu_D0_eta", &BsDstarTauNu_D0_eta );
    tree_->Branch("BsDstarTauNu_D0_phi", &BsDstarTauNu_D0_phi );
    tree_->Branch("BsDstarTauNu_D0_mass", &BsDstarTauNu_D0_mass );
    tree_->Branch("BsDstarTauNu_D0_vprob", &BsDstarTauNu_D0_vprob );
    tree_->Branch("BsDstarTauNu_D0_lip", &BsDstarTauNu_D0_lip);
    tree_->Branch("BsDstarTauNu_D0_lips", &BsDstarTauNu_D0_lips);
    tree_->Branch("BsDstarTauNu_D0_pvip", &BsDstarTauNu_D0_pvip);
    tree_->Branch("BsDstarTauNu_D0_pvips", &BsDstarTauNu_D0_pvips);
    tree_->Branch("BsDstarTauNu_D0_fl3d", &BsDstarTauNu_D0_fl3d);
    tree_->Branch("BsDstarTauNu_D0_fls3d", &BsDstarTauNu_D0_fls3d);
    tree_->Branch("BsDstarTauNu_D0_alpha", &BsDstarTauNu_D0_alpha);
    tree_->Branch("BsDstarTauNu_D0_vx", &BsDstarTauNu_D0_vx );
    tree_->Branch("BsDstarTauNu_D0_vy", &BsDstarTauNu_D0_vy );
    tree_->Branch("BsDstarTauNu_D0_vz", &BsDstarTauNu_D0_vz );
    tree_->Branch("BsDstarTauNu_D0_unfit_pt", &BsDstarTauNu_D0_unfit_pt );
    tree_->Branch("BsDstarTauNu_D0_unfit_mass", &BsDstarTauNu_D0_unfit_mass );
    tree_->Branch("BsDstarTauNu_D0_ptfrac", &BsDstarTauNu_D0_ptfrac );

    tree_->Branch("BsDstarTauNu_k_charge", &BsDstarTauNu_k_charge );
    tree_->Branch("BsDstarTauNu_pi_charge", &BsDstarTauNu_pi_charge );
    tree_->Branch("BsDstarTauNu_spi_charge", &BsDstarTauNu_spi_charge );

    tree_->Branch("BsDstarTauNu_B_pt", &BsDstarTauNu_B_pt );
    tree_->Branch("BsDstarTauNu_B_eta", &BsDstarTauNu_B_eta );
    tree_->Branch("BsDstarTauNu_B_phi", &BsDstarTauNu_B_phi );
    tree_->Branch("BsDstarTauNu_B_mass", &BsDstarTauNu_B_mass );
    tree_->Branch("BsDstarTauNu_B_vprob", &BsDstarTauNu_B_vprob );
    tree_->Branch("BsDstarTauNu_B_lip", &BsDstarTauNu_B_lip);
    tree_->Branch("BsDstarTauNu_B_lips", &BsDstarTauNu_B_lips);
    tree_->Branch("BsDstarTauNu_B_pvip", &BsDstarTauNu_B_pvip);
    tree_->Branch("BsDstarTauNu_B_pvips", &BsDstarTauNu_B_pvips);
    tree_->Branch("BsDstarTauNu_B_fl3d", &BsDstarTauNu_B_fl3d);
    tree_->Branch("BsDstarTauNu_B_fls3d", &BsDstarTauNu_B_fls3d);
    tree_->Branch("BsDstarTauNu_B_alpha", &BsDstarTauNu_B_alpha);
    tree_->Branch("BsDstarTauNu_B_maxdoca", &BsDstarTauNu_B_maxdoca);
    tree_->Branch("BsDstarTauNu_B_mindoca", &BsDstarTauNu_B_mindoca);
    tree_->Branch("BsDstarTauNu_B_vx", &BsDstarTauNu_B_vx );
    tree_->Branch("BsDstarTauNu_B_vy", &BsDstarTauNu_B_vy );
    tree_->Branch("BsDstarTauNu_B_vz", &BsDstarTauNu_B_vz );
    tree_->Branch("BsDstarTauNu_B_iso", &BsDstarTauNu_B_iso);
    tree_->Branch("BsDstarTauNu_B_iso_ntracks", &BsDstarTauNu_B_iso_ntracks );
    tree_->Branch("BsDstarTauNu_B_iso_mindoca", &BsDstarTauNu_B_iso_mindoca );
    tree_->Branch("BsDstarTauNu_B_mm2", &BsDstarTauNu_B_mm2 );
    tree_->Branch("BsDstarTauNu_B_q2", &BsDstarTauNu_B_q2 );
    tree_->Branch("BsDstarTauNu_B_Es", &BsDstarTauNu_B_Es );
    tree_->Branch("BsDstarTauNu_B_ptback", &BsDstarTauNu_B_ptback );

    tree_->Branch("BsDstarTauNu_ngenmuons", &BsDstarTauNu_ngenmuons);
    tree_->Branch("BsDstarTauNu_isgen3", &BsDstarTauNu_isgen3);
    tree_->Branch("BsDstarTauNu_isgen3matched", &BsDstarTauNu_isgen3matched);
    tree_->Branch("BsDstarTauNu_nch", &BsDstarTauNu_nch);
    tree_->Branch("BsDstarTauNu_nch_after_dnn", &BsDstarTauNu_nch_after_dnn);
    tree_->Branch("BsDstarTauNu_nch_before_dnn", &BsDstarTauNu_nch_before_dnn);
    tree_->Branch("BsDstarTauNu_nch_qr", &BsDstarTauNu_nch_qr);
    tree_->Branch("BsDstarTauNu_ngentau3", &BsDstarTauNu_ngentau3); 
    tree_->Branch("BsDstarTauNu_ngentau", &BsDstarTauNu_ngentau);
    tree_->Branch("BsDstarTauNu_gentaupt", &BsDstarTauNu_gentaupt);
    tree_->Branch("BsDstarTauNu_gentaudm", &BsDstarTauNu_gentaudm);
    
  }

}

//=================================================================================================================== 
void NtupleBranches::reset( void ){

  /** genParticle */
  genParticle_N = 0;
  genParticle_pt.clear();
//  genParticle_px.clear();
//  genParticle_py.clear();
//  genParticle_pz.clear();
//  genParticle_e.clear();
  genParticle_eta.clear();
  genParticle_phi.clear();
  genParticle_mass.clear();
  genParticle_pdgId.clear();
  genParticle_isPrompt.clear();
  genParticle_isDirectPromptTauDecayProduct.clear();
  genParticle_fromHardProcessFinalState.clear();
  genParticle_isDirectHardProcessTauDecayProductFinalState.clear();
  genParticle_status.clear();
  genParticle_mother.clear();
  genParticle_nMoth.clear();
  genParticle_nDau.clear();
  genParticle_dau.clear();
  
  /** generator info */
  genWeight   = 0;
  qScale      = 0;
  genFacWeightUp       = 0;
  genFacWeightDown     = 0;
  genRenWeightUp       = 0;
  genRenWeightDown     = 0;
  genFacRenWeightUp    = 0;
  genFacRenWeightDown  = 0;
  PDF_rms = 0;
  PDF_id.clear();  
  PDF_x.clear();	
  PDF_xPDF.clear();
  lheV_pt = 0;
  lheHT = 0;
  lheNj = 0;
  lheNb = 0;
  lheV_mass = 0;
    
 

  /** HLT trigger decisions */
  HLT_isFired.clear();
  
  /** HLT trigger objects */
  triggerObject_pt.clear();
  triggerObject_eta.clear();
  triggerObject_phi.clear();
  triggerObject_mass.clear();
  triggerObject_lastname.clear();
  triggerObject_filterIDs.clear();
  triggerObject_filterLabels.clear();
  triggerObject_firedTrigger.clear();

  /** HLT filter decisions */
  passFilter_HBHE_                  = false;
  passFilter_HBHELoose_             = false;
  passFilter_HBHETight_             = false;
  passFilter_HBHEIso_               = false;
  passFilter_CSCHalo_               = false;
  passFilter_CSCTightHalo2015_      = false;
  passFilter_HCALlaser_             = false;
  passFilter_ECALDeadCell_          = false;
  passFilter_GoodVtx_               = false;
  passFilter_TrkFailure_            = false;
  passFilter_EEBadSc_               = false;
  passFilter_ECALlaser_             = false;
  passFilter_TrkPOG_                = false;
  passFilter_TrkPOG_manystrip_      = false;
  passFilter_TrkPOG_toomanystrip_   = false;
  passFilter_TrkPOG_logError_       = false;
  passFilter_METFilters_            = false;
   //NEW FOR ICHEP
  passFilter_CSCTightHaloTrkMuUnvetoFilter_   = false;
  passFilter_globalTightHalo2016_             = false;
  passFilter_globalSuperTightHalo2016_             = false;
  passFilter_HcalStripHalo_                   = false;
  passFilter_chargedHadronTrackResolution_    = false;
  passFilter_muonBadTrack_                    = false;
  flag_badMuons_                    = false;
  flag_duplicateMuons_              = false;
  flag_nobadMuons_                  = false;

  /** energy density */
  rho = 0;
  
 

  /** MET */
  METraw_et.clear();	 
  METraw_phi.clear();
  METraw_sumEt.clear();
  MET_corrPx.clear();
  MET_corrPy.clear();
  MET_et.clear();
  MET_phi.clear();
  MET_puppi_et.clear();
  MET_puppi_phi.clear();

  MET_sumEt.clear();
  MET_T1Uncertainty.clear();
  
  MET_JetEnUp.clear();
  MET_JetEnDown.clear();
  MET_JetResUp.clear();
  MET_JetResDown.clear();
  MET_UnclusteredEnUp.clear();
  MET_UnclusteredEnDown.clear();

  /** MET SVift*/
  MET_significance.clear();
  MET_cov00.clear();
  MET_cov10.clear();
  MET_cov11.clear();
  MET_mva_et.clear();
  MET_mva_phi.clear();
  MET_mva_cov00.clear();
  MET_mva_cov10.clear();
  MET_mva_cov11.clear();
  MET_mva_recoil_pt.clear();
  MET_mva_recoil_eta.clear();
  MET_mva_recoil_phi.clear();
  MET_mva_recoil_pdgId.clear();
  MET_Nmva.clear();

  /*------------------------EVENT infos-------------------------*/    
  EVENT_event = 0;
  EVENT_run = 0;
  EVENT_lumiBlock = 0;

  /*--------------------------PV infos--------------------------*/
  PV_N = 0;
  PV_filter = true;
  PV_chi2.clear();
  PV_ndof.clear();
  PV_rho.clear();
  PV_z.clear();
  BeamSpot_x0.clear();
  BeamSpot_y0.clear();
  BeamSpot_z0.clear();
  /*--------------------------PU infos--------------------------*/  			       
  nPuVtxTrue.clear();
  nPuVtx.clear();
  bX.clear();

  /*-------------------------JPSI infos--------------------------*/ 
  IsJpsiMu.clear();
  IsJpsiTau.clear();
  IsBsTauTau.clear();
  IsBsTauTauFH.clear();
  IsBsDstarTauNu.clear();

  JpsiMu_nCandidates.clear();
  JpsiMu_mu1_pt.clear();
  JpsiMu_mu1_eta.clear();
  JpsiMu_mu1_phi.clear();
  JpsiMu_mu1_mass.clear();
  JpsiMu_mu1_unfit_pt.clear();
  JpsiMu_mu1_unfit_eta.clear();
  JpsiMu_mu1_unfit_phi.clear();
  JpsiMu_mu1_unfit_mass.clear();
  JpsiMu_mu1_q.clear();
  JpsiMu_mu1_isLoose.clear();
  JpsiMu_mu1_isTight.clear();
  JpsiMu_mu1_isPF.clear();
  JpsiMu_mu1_isGlobal.clear();
  JpsiMu_mu1_isTracker.clear();
  JpsiMu_mu1_isSoft.clear();
  JpsiMu_mu1_vx.clear();
  JpsiMu_mu1_vy.clear();
  JpsiMu_mu1_vz.clear();
  JpsiMu_mu1_iso.clear();
  JpsiMu_mu1_dbiso.clear();

  JpsiMu_mu2_pt.clear();
  JpsiMu_mu2_eta.clear();
  JpsiMu_mu2_phi.clear();
  JpsiMu_mu2_mass.clear();
  JpsiMu_mu2_unfit_pt.clear();
  JpsiMu_mu2_unfit_eta.clear();
  JpsiMu_mu2_unfit_phi.clear();
  JpsiMu_mu2_unfit_mass.clear();
  JpsiMu_mu2_q.clear();
  JpsiMu_mu2_isLoose.clear();
  JpsiMu_mu2_isTight.clear();
  JpsiMu_mu2_isPF.clear();
  JpsiMu_mu2_isGlobal.clear();
  JpsiMu_mu2_isTracker.clear();
  JpsiMu_mu2_isSoft.clear();
  JpsiMu_mu2_vx.clear();
  JpsiMu_mu2_vy.clear();
  JpsiMu_mu2_vz.clear();
  JpsiMu_mu2_iso.clear();
  JpsiMu_mu2_dbiso.clear();

  JpsiMu_mu3_pt.clear();
  JpsiMu_mu3_eta.clear();
  JpsiMu_mu3_phi.clear();
  JpsiMu_mu3_mass.clear();
  JpsiMu_mu3_unfit_pt.clear();
  JpsiMu_mu3_unfit_eta.clear();
  JpsiMu_mu3_unfit_phi.clear();
  JpsiMu_mu3_unfit_mass.clear();
  JpsiMu_mu3_doca2mu1.clear();
  JpsiMu_mu3_doca2mu2.clear();
  JpsiMu_mu3_q.clear();
  JpsiMu_mu3_isLoose.clear();
  JpsiMu_mu3_isTight.clear();
  JpsiMu_mu3_isPF.clear();
  JpsiMu_mu3_isGlobal.clear();
  JpsiMu_mu3_isTracker.clear();
  JpsiMu_mu3_isSoft.clear();
  JpsiMu_mu3_vx.clear();
  JpsiMu_mu3_vy.clear();
  JpsiMu_mu3_vz.clear();
  JpsiMu_mu3_iso.clear();
  JpsiMu_mu3_dbiso.clear();

  JpsiMu_Jpsi_pt.clear();
  JpsiMu_Jpsi_eta.clear();
  JpsiMu_Jpsi_phi.clear();
  JpsiMu_Jpsi_mass.clear();
  JpsiMu_Jpsi_vprob.clear();
  JpsiMu_Jpsi_lip.clear();
  JpsiMu_Jpsi_lips.clear();
  JpsiMu_Jpsi_pvip.clear();
  JpsiMu_Jpsi_pvips.clear();
  JpsiMu_Jpsi_fl3d.clear();
  JpsiMu_Jpsi_fls3d.clear();
  JpsiMu_Jpsi_alpha.clear();
  JpsiMu_Jpsi_maxdoca.clear();
  JpsiMu_Jpsi_mindoca.clear();
  JpsiMu_Jpsi_vx.clear();
  JpsiMu_Jpsi_vy.clear();
  JpsiMu_Jpsi_vz.clear();
  JpsiMu_Jpsi_unfit_pt.clear();
  JpsiMu_Jpsi_unfit_mass.clear();
  JpsiMu_Jpsi_unfit_vprob.clear();
  JpsiMu_Jpsi_unfit_vx.clear();
  JpsiMu_Jpsi_unfit_vy.clear();
  JpsiMu_Jpsi_unfit_vz.clear();

  JpsiMu_B_pt.clear();
  JpsiMu_B_eta.clear();
  JpsiMu_B_phi.clear();
  JpsiMu_B_mass.clear();
  JpsiMu_B_vprob.clear();
  JpsiMu_B_lip.clear();
  JpsiMu_B_lips.clear();
  JpsiMu_B_pvip.clear();
  JpsiMu_B_pvips.clear();
  JpsiMu_B_fl3d.clear();
  JpsiMu_B_fls3d.clear();
  JpsiMu_B_alpha.clear();
  JpsiMu_B_maxdoca.clear();
  JpsiMu_B_mindoca.clear();
  JpsiMu_B_vx.clear();
  JpsiMu_B_vy.clear();
  JpsiMu_B_vz.clear();
  JpsiMu_B_iso.clear();
  JpsiMu_B_iso_ntracks.clear();
  JpsiMu_B_iso_mindoca.clear();
  JpsiMu_B_unfit_pt.clear();
  JpsiMu_B_unfit_mass.clear();
  JpsiMu_B_unfit_vprob.clear();
  JpsiMu_B_unfit_vx.clear();
  JpsiMu_B_unfit_vy.clear();
  JpsiMu_B_unfit_vz.clear();

  JpsiMu_PV_vx.clear();
  JpsiMu_PV_vy.clear();
  JpsiMu_PV_vz.clear();

  JpsiMu_bbPV_vx.clear();
  JpsiMu_bbPV_vy.clear();
  JpsiMu_bbPV_vz.clear();

  JpsiMu_bbPV_refit_vx.clear();
  JpsiMu_bbPV_refit_vy.clear();
  JpsiMu_bbPV_refit_vz.clear();

  JpsiMu_genPV_vx.clear();
  JpsiMu_genPV_vy.clear();
  JpsiMu_genPV_vz.clear();

  JpsiMu_ngenmuons.clear();
  JpsiMu_isgenmatched.clear();
  JpsiMu_mu3_isgenmatched.clear();






  JpsiTau_nCandidates.clear();

  JpsiTau_mu1_pt.clear();
  JpsiTau_mu1_eta.clear();
  JpsiTau_mu1_phi.clear();
  JpsiTau_mu1_mass.clear();
  JpsiTau_mu1_q.clear();
  JpsiTau_mu1_isLoose.clear();
  JpsiTau_mu1_isTight.clear();
  JpsiTau_mu1_isPF.clear();
  JpsiTau_mu1_isGlobal.clear();
  JpsiTau_mu1_isTracker.clear();
  JpsiTau_mu1_isSoft.clear();
  JpsiTau_mu1_vx.clear();
  JpsiTau_mu1_vy.clear();
  JpsiTau_mu1_vz.clear();
  JpsiTau_mu1_iso.clear();
  JpsiTau_mu1_dbiso.clear();

  JpsiTau_mu2_pt.clear();
  JpsiTau_mu2_eta.clear();
  JpsiTau_mu2_phi.clear();
  JpsiTau_mu2_mass.clear();
  JpsiTau_mu2_q.clear();
  JpsiTau_mu2_isLoose.clear();
  JpsiTau_mu2_isTight.clear();
  JpsiTau_mu2_isPF.clear();
  JpsiTau_mu2_isGlobal.clear();
  JpsiTau_mu2_isTracker.clear();
  JpsiTau_mu2_isSoft.clear();
  JpsiTau_mu2_vx.clear();
  JpsiTau_mu2_vy.clear();
  JpsiTau_mu2_vz.clear();
  JpsiTau_mu2_iso.clear();
  JpsiTau_mu2_dbiso.clear();

  //  JpsiTau_tau_fullfit_pt.clear();
  //  JpsiTau_tau_fullfit_eta.clear();
  //  JpsiTau_tau_fullfit_phi.clear();
  //  JpsiTau_tau_fullfit_mass.clear();
  JpsiTau_tau_pt.clear();
  JpsiTau_tau_eta.clear();
  JpsiTau_tau_phi.clear();
  JpsiTau_tau_mass.clear();
  JpsiTau_tau_q.clear();
  JpsiTau_tau_vx.clear();
  JpsiTau_tau_vy.clear();
  JpsiTau_tau_vz.clear();


  JpsiTau_tau_max_dr_3prong.clear();
  JpsiTau_tau_lip.clear();
  JpsiTau_tau_lips.clear();
  JpsiTau_tau_pvip.clear();
  JpsiTau_tau_pvips.clear();
  JpsiTau_tau_fl3d.clear();
  JpsiTau_tau_fls3d.clear();
  JpsiTau_tau_alpha.clear();
  JpsiTau_tau_vprob.clear();
  JpsiTau_tau_isRight.clear();
  JpsiTau_tau_isRight1.clear();
  JpsiTau_tau_isRight2.clear();
  JpsiTau_tau_isRight3.clear();
  JpsiTau_tau_dr1.clear();
  JpsiTau_tau_dr2.clear();
  JpsiTau_tau_dr3.clear();
  JpsiTau_tau_ptres1.clear();
  JpsiTau_tau_ptres2.clear();
  JpsiTau_tau_ptres3.clear();
  JpsiTau_tau_matched_ppdgId.clear();
  JpsiTau_tau_matched_gentaupt.clear();
  JpsiTau_tau_sumofdnn.clear();
  JpsiTau_tau_pfidx1.clear();
  JpsiTau_tau_pfidx2.clear();
  JpsiTau_tau_pfidx3.clear();
  JpsiTau_tau_pi1_dnn.clear();
  JpsiTau_tau_pi2_dnn.clear();
  JpsiTau_tau_pi3_dnn.clear();

  JpsiTau_tau_rhomass1.clear();
  JpsiTau_tau_rhomass2.clear();

  JpsiTau_tau_pi1_pt.clear();
  JpsiTau_tau_pi1_eta.clear();
  JpsiTau_tau_pi1_phi.clear();
  JpsiTau_tau_pi1_mass.clear();
  JpsiTau_tau_pi1_q.clear();
  JpsiTau_tau_pi2_pt.clear();
  JpsiTau_tau_pi2_eta.clear();
  JpsiTau_tau_pi2_phi.clear();
  JpsiTau_tau_pi2_mass.clear();
  JpsiTau_tau_pi2_q.clear();
  JpsiTau_tau_pi3_pt.clear();
  JpsiTau_tau_pi3_eta.clear();
  JpsiTau_tau_pi3_phi.clear();
  JpsiTau_tau_pi3_mass.clear();
  JpsiTau_tau_pi3_q.clear();

  JpsiTau_Jpsi_pt.clear();
  JpsiTau_Jpsi_eta.clear();
  JpsiTau_Jpsi_phi.clear();
  JpsiTau_Jpsi_mass.clear();
  JpsiTau_Jpsi_vprob.clear();
  JpsiTau_Jpsi_lip.clear();
  JpsiTau_Jpsi_lips.clear();
  JpsiTau_Jpsi_pvip.clear();
  JpsiTau_Jpsi_pvips.clear();
  JpsiTau_Jpsi_fl3d.clear();
  JpsiTau_Jpsi_fls3d.clear();
  JpsiTau_Jpsi_alpha.clear();
  JpsiTau_Jpsi_maxdoca.clear();
  JpsiTau_Jpsi_mindoca.clear();
  JpsiTau_Jpsi_vx.clear();
  JpsiTau_Jpsi_vy.clear();
  JpsiTau_Jpsi_vz.clear();
  JpsiTau_Jpsi_unfit_pt.clear();
  JpsiTau_Jpsi_unfit_mass.clear();
  JpsiTau_Jpsi_unfit_vprob.clear();
  JpsiTau_Jpsi_unfit_vx.clear();
  JpsiTau_Jpsi_unfit_vy.clear();
  JpsiTau_Jpsi_unfit_vz.clear();

  JpsiTau_B_pt.clear();
  JpsiTau_B_eta.clear();
  JpsiTau_B_phi.clear();
  JpsiTau_B_mass.clear();
  JpsiTau_B_vprob.clear();
  JpsiTau_B_lip.clear();
  JpsiTau_B_lips.clear();
  JpsiTau_B_pvip.clear();
  JpsiTau_B_pvips.clear();
  JpsiTau_B_fl3d.clear();
  JpsiTau_B_fls3d.clear();
  JpsiTau_B_alpha.clear();
  JpsiTau_B_maxdoca.clear();
  JpsiTau_B_mindoca.clear();
  JpsiTau_B_vx.clear();
  JpsiTau_B_vy.clear();
  JpsiTau_B_vz.clear();
  JpsiTau_B_iso.clear();
  JpsiTau_B_iso_ntracks.clear();
  JpsiTau_B_iso_mindoca.clear();

  JpsiTau_PV_vx.clear();
  JpsiTau_PV_vy.clear();
  JpsiTau_PV_vz.clear();

  JpsiTau_bbPV_vx.clear();
  JpsiTau_bbPV_vy.clear();
  JpsiTau_bbPV_vz.clear();

  JpsiTau_bbPV_refit_vx.clear();
  JpsiTau_bbPV_refit_vy.clear();
  JpsiTau_bbPV_refit_vz.clear();

  JpsiTau_genPV_vx.clear();
  JpsiTau_genPV_vy.clear();
  JpsiTau_genPV_vz.clear();

  JpsiTau_ngenmuons.clear();
  JpsiTau_isgenmatched.clear();

  JpsiTau_isgen3.clear();
  JpsiTau_isgen3matched.clear();
  JpsiTau_nch.clear();
  JpsiTau_nch_after_dnn.clear();
  JpsiTau_nch_before_dnn.clear();
  JpsiTau_nch_qr.clear();
  JpsiTau_ngentau3.clear();
  JpsiTau_ngentau.clear();
  JpsiTau_gentaupt.clear();
  JpsiTau_gentaudm.clear();



  /////////////////

  //TriggerName.clear(); //change
  BsTauTau_nCandidates.clear();

  BsTauTau_mu1_pt.clear();
  BsTauTau_mu1_eta.clear();
  BsTauTau_mu1_phi.clear();
  BsTauTau_mu1_mass.clear();
  BsTauTau_mu1_q.clear();
  BsTauTau_mu1_isLoose.clear();
  BsTauTau_mu1_isTight.clear();
  BsTauTau_mu1_isPF.clear();
  BsTauTau_mu1_isGlobal.clear();
  BsTauTau_mu1_isTracker.clear();
  BsTauTau_mu1_isSoft.clear();
  BsTauTau_mu1_vx.clear();
  BsTauTau_mu1_vy.clear();
  BsTauTau_mu1_vz.clear();
  BsTauTau_mu1_iso.clear();
  BsTauTau_mu1_dbiso.clear();

  BsTauTau_tau_pt.clear();
  BsTauTau_tau_eta.clear();
  BsTauTau_tau_phi.clear();
  BsTauTau_tau_mass.clear();
  BsTauTau_tau_rhomass1.clear();
  BsTauTau_tau_rhomass2.clear();
  BsTauTau_tau_q.clear();
  BsTauTau_tau_vx.clear();
  BsTauTau_tau_vy.clear();
  BsTauTau_tau_vz.clear();


  BsTauTau_tau_max_dr_3prong.clear();
  BsTauTau_tau_lip.clear();
  BsTauTau_tau_lips.clear();
  BsTauTau_tau_pvip.clear();
  BsTauTau_tau_pvips.clear();
  BsTauTau_tau_fl3d.clear();
  BsTauTau_tau_fls3d.clear();
  BsTauTau_tau_alpha.clear();
  BsTauTau_tau_vprob.clear();
  BsTauTau_tau_isRight.clear();
  BsTauTau_tau_isRight1.clear();
  BsTauTau_tau_isRight2.clear();
  BsTauTau_tau_isRight3.clear();
  BsTauTau_tau_dr1.clear();
  BsTauTau_tau_dr2.clear();
  BsTauTau_tau_dr3.clear();
  BsTauTau_tau_muon_dr1.clear(); //change
  BsTauTau_tau_muon_dr2.clear(); //change
  BsTauTau_tau_muon_dr3.clear(); //change
  BsTauTau_tau_pi1_dz.clear();//change
  BsTauTau_tau_pi2_dz.clear();//change
  BsTauTau_tau_pi3_dz.clear(); //change
  BsTauTau_tau_ptres1.clear(); 
  BsTauTau_tau_ptres2.clear();
  BsTauTau_tau_ptres3.clear();
  BsTauTau_tau_matched_ppdgId.clear();
  BsTauTau_tau_matched_gentaupt.clear();
  BsTauTau_tau_sumofdnn.clear();
  BsTauTau_tau_pfidx1.clear();
  BsTauTau_tau_pfidx2.clear();
  BsTauTau_tau_pfidx3.clear();
  BsTauTau_tau_pi1_dnn.clear();
  BsTauTau_tau_pi2_dnn.clear();
  BsTauTau_tau_pi3_dnn.clear();

  BsTauTau_tau_pi1_pt.clear();
  BsTauTau_tau_pi1_eta.clear();
  BsTauTau_tau_pi1_phi.clear();
  BsTauTau_tau_pi1_mass.clear();
  BsTauTau_tau_pi1_charge.clear(); //change

  BsTauTau_tau_pi2_pt.clear();
  BsTauTau_tau_pi2_eta.clear();
  BsTauTau_tau_pi2_phi.clear();
  BsTauTau_tau_pi2_mass.clear();
  BsTauTau_tau_pi2_charge.clear(); //change

  BsTauTau_tau_pi3_pt.clear();
  BsTauTau_tau_pi3_eta.clear();
  BsTauTau_tau_pi3_phi.clear();
  BsTauTau_tau_pi3_mass.clear();
  BsTauTau_tau_pi3_charge.clear(); //change


  BsTauTau_B_pt.clear();
  BsTauTau_B_eta.clear();
  BsTauTau_B_phi.clear();
  BsTauTau_B_mass.clear();
  BsTauTau_B_vprob.clear();
  BsTauTau_B_lip.clear();
  BsTauTau_B_lips.clear();
  BsTauTau_B_pvip.clear();
  BsTauTau_B_pvips.clear();
  BsTauTau_B_fl3d.clear();
  BsTauTau_B_fls3d.clear();
  BsTauTau_B_alpha.clear();
  BsTauTau_B_maxdoca.clear();
  BsTauTau_B_mindoca.clear();

  BsTauTau_muonpion_maxdoca.clear();
  BsTauTau_muonpion_mindoca.clear();
  BsTauTau_B_vx.clear();
  BsTauTau_B_vy.clear();
  BsTauTau_B_vz.clear();
  BsTauTau_B_iso.clear();
  BsTauTau_B_iso_ntracks.clear();
  BsTauTau_B_iso_mindoca.clear();

  BsTauTau_PV_vx.clear();
  BsTauTau_PV_vy.clear();
  BsTauTau_PV_vz.clear();

  BsTauTau_bbPV_vx.clear();
  BsTauTau_bbPV_vy.clear();
  BsTauTau_bbPV_vz.clear();

  BsTauTau_bbPV_refit_vx.clear();
  BsTauTau_bbPV_refit_vy.clear();
  BsTauTau_bbPV_refit_vz.clear();

  BsTauTau_genPV_vx.clear();
  BsTauTau_genPV_vy.clear();
  BsTauTau_genPV_vz.clear();

  BsTauTau_ngenmuons.clear();

  BsTauTau_isgen3.clear();
  BsTauTau_isgen3matched.clear();
  BsTauTau_nch.clear();
  BsTauTau_nch_after_dnn.clear();
  BsTauTau_nch_before_dnn.clear();
  BsTauTau_nch_qr.clear();
  BsTauTau_ngentau3.clear();
  BsTauTau_ngentau.clear();
  BsTauTau_gentaupt.clear();
  BsTauTau_gentaudm.clear();



  ///////////////////////////////



  BsTauTauFH_nCandidates.clear();
  BsTauTauFH_ntaus.clear();

  BsTauTauFH_mu1_pt.clear();
  BsTauTauFH_mu1_eta.clear();
  BsTauTauFH_mu1_phi.clear();
  BsTauTauFH_mu1_mass.clear();
  BsTauTauFH_mu1_q.clear();
  BsTauTauFH_mu1_isLoose.clear();
  BsTauTauFH_mu1_isTight.clear();
  BsTauTauFH_mu1_isPF.clear();
  BsTauTauFH_mu1_isGlobal.clear();
  BsTauTauFH_mu1_isTracker.clear();
  BsTauTauFH_mu1_isSoft.clear();
  BsTauTauFH_mu1_vx.clear();
  BsTauTauFH_mu1_vy.clear();
  BsTauTauFH_mu1_vz.clear();
  BsTauTauFH_mu1_iso.clear();
  BsTauTauFH_mu1_dbiso.clear();


  BsTauTauFH_tau1_pt.clear();
  BsTauTauFH_tau1_eta.clear();
  BsTauTauFH_tau1_phi.clear();
  BsTauTauFH_tau1_mass.clear();
  BsTauTauFH_tau1_rhomass1.clear();
  BsTauTauFH_tau1_rhomass2.clear();
  BsTauTauFH_tau1_q.clear();
  BsTauTauFH_tau1_vx.clear();
  BsTauTauFH_tau1_vy.clear();
  BsTauTauFH_tau1_vz.clear();


  BsTauTauFH_tau1_max_dr_3prong.clear();
  BsTauTauFH_tau1_lip.clear();
  BsTauTauFH_tau1_lips.clear();
  BsTauTauFH_tau1_pvip.clear();
  BsTauTauFH_tau1_pvips.clear();
  BsTauTauFH_tau1_fl3d.clear();
  BsTauTauFH_tau1_fls3d.clear();
  BsTauTauFH_tau1_alpha.clear();
  BsTauTauFH_tau1_vprob.clear();
  BsTauTauFH_tau1_isRight.clear();
  BsTauTauFH_tau1_matched_ppdgId.clear();
  BsTauTauFH_tau1_matched_gentaupt.clear();
  BsTauTauFH_tau1_sumofdnn.clear();
  BsTauTauFH_tau1_pfidx1.clear();
  BsTauTauFH_tau1_pfidx2.clear();
  BsTauTauFH_tau1_pfidx3.clear();
  BsTauTauFH_tau1_pi1_dnn.clear();
  BsTauTauFH_tau1_pi2_dnn.clear();
  BsTauTauFH_tau1_pi3_dnn.clear();

  BsTauTauFH_tau1_pi1_pt.clear();
  BsTauTauFH_tau1_pi1_eta.clear();
  BsTauTauFH_tau1_pi1_phi.clear();
  BsTauTauFH_tau1_pi1_mass.clear();

  BsTauTauFH_tau1_pi2_pt.clear();
  BsTauTauFH_tau1_pi2_eta.clear();
  BsTauTauFH_tau1_pi2_phi.clear();
  BsTauTauFH_tau1_pi2_mass.clear();

  BsTauTauFH_tau1_pi3_pt.clear();
  BsTauTauFH_tau1_pi3_eta.clear();
  BsTauTauFH_tau1_pi3_phi.clear();
  BsTauTauFH_tau1_pi3_mass.clear();


  BsTauTauFH_tau2_pt.clear();
  BsTauTauFH_tau2_eta.clear();
  BsTauTauFH_tau2_phi.clear();
  BsTauTauFH_tau2_mass.clear();
  BsTauTauFH_tau2_rhomass1.clear();
  BsTauTauFH_tau2_rhomass2.clear();
  BsTauTauFH_tau2_q.clear();
  BsTauTauFH_tau2_vx.clear();
  BsTauTauFH_tau2_vy.clear();
  BsTauTauFH_tau2_vz.clear();


  BsTauTauFH_tau2_max_dr_3prong.clear();
  BsTauTauFH_tau2_lip.clear();
  BsTauTauFH_tau2_lips.clear();
  BsTauTauFH_tau2_pvip.clear();
  BsTauTauFH_tau2_pvips.clear();
  BsTauTauFH_tau2_fl3d.clear();
  BsTauTauFH_tau2_fls3d.clear();
  BsTauTauFH_tau2_alpha.clear();
  BsTauTauFH_tau2_vprob.clear();
  BsTauTauFH_tau2_isRight.clear();
  BsTauTauFH_tau2_matched_ppdgId.clear();
  BsTauTauFH_tau2_matched_gentaupt.clear();
  BsTauTauFH_tau2_sumofdnn.clear();
  BsTauTauFH_tau2_pfidx1.clear();
  BsTauTauFH_tau2_pfidx2.clear();
  BsTauTauFH_tau2_pfidx3.clear();
  BsTauTauFH_tau2_pi1_dnn.clear();
  BsTauTauFH_tau2_pi2_dnn.clear();
  BsTauTauFH_tau2_pi3_dnn.clear();

  BsTauTauFH_tau2_pi1_pt.clear();
  BsTauTauFH_tau2_pi1_eta.clear();
  BsTauTauFH_tau2_pi1_phi.clear();
  BsTauTauFH_tau2_pi1_mass.clear();

  BsTauTauFH_tau2_pi2_pt.clear();
  BsTauTauFH_tau2_pi2_eta.clear();
  BsTauTauFH_tau2_pi2_phi.clear();
  BsTauTauFH_tau2_pi2_mass.clear();

  BsTauTauFH_tau2_pi3_pt.clear();
  BsTauTauFH_tau2_pi3_eta.clear();
  BsTauTauFH_tau2_pi3_phi.clear();
  BsTauTauFH_tau2_pi3_mass.clear();

  BsTauTauFH_B_pt.clear();
  BsTauTauFH_B_eta.clear();
  BsTauTauFH_B_phi.clear();
  BsTauTauFH_B_mass.clear();
  BsTauTauFH_B_vprob.clear();
  BsTauTauFH_B_lip.clear();
  BsTauTauFH_B_lips.clear();
  BsTauTauFH_B_pvip.clear();
  BsTauTauFH_B_pvips.clear();
  BsTauTauFH_B_fl3d.clear();
  BsTauTauFH_B_fls3d.clear();
  BsTauTauFH_B_alpha.clear();
  BsTauTauFH_B_maxdoca.clear();
  BsTauTauFH_B_mindoca.clear();
  BsTauTauFH_B_vx.clear();
  BsTauTauFH_B_vy.clear();
  BsTauTauFH_B_vz.clear();
  BsTauTauFH_B_iso.clear();
  BsTauTauFH_B_iso_ntracks.clear();
  BsTauTauFH_B_iso_mindoca.clear();

  BsTauTauFH_PV_vx.clear();
  BsTauTauFH_PV_vy.clear();
  BsTauTauFH_PV_vz.clear();

  BsTauTauFH_bbPV_vx.clear();
  BsTauTauFH_bbPV_vy.clear();
  BsTauTauFH_bbPV_vz.clear();

  BsTauTauFH_bbPV_refit_vx.clear();
  BsTauTauFH_bbPV_refit_vy.clear();
  BsTauTauFH_bbPV_refit_vz.clear();

  BsTauTauFH_genPV_vx.clear();
  BsTauTauFH_genPV_vy.clear();
  BsTauTauFH_genPV_vz.clear();

  BsTauTauFH_ngenmuons.clear();

  BsTauTauFH_isgen3.clear();
  BsTauTauFH_isgen3matched.clear();
  BsTauTauFH_nch.clear();
  BsTauTauFH_nch_after_dnn.clear();
  BsTauTauFH_nch_before_dnn.clear();
  BsTauTauFH_nch_qr.clear();
  BsTauTauFH_ngentau3.clear();
  BsTauTauFH_ngentau.clear();
  BsTauTauFH_gentaupt.clear();
  BsTauTauFH_gentaudm.clear();


  //////////////////////////////


  BsDstarTauNu_nCandidates.clear();


  BsDstarTauNu_mu1_pt.clear();
  BsDstarTauNu_mu1_eta.clear();
  BsDstarTauNu_mu1_phi.clear();
  BsDstarTauNu_mu1_mass.clear();
  BsDstarTauNu_mu1_q.clear();
  BsDstarTauNu_mu1_isLoose.clear();
  BsDstarTauNu_mu1_isTight.clear();
  BsDstarTauNu_mu1_isPF.clear();
  BsDstarTauNu_mu1_isGlobal.clear();
  BsDstarTauNu_mu1_isTracker.clear();
  BsDstarTauNu_mu1_isSoft.clear();
  BsDstarTauNu_mu1_vx.clear();
  BsDstarTauNu_mu1_vy.clear();
  BsDstarTauNu_mu1_vz.clear();
  BsDstarTauNu_mu1_iso.clear();
  BsDstarTauNu_mu1_dbiso.clear();

  BsDstarTauNu_tau_fullfit_pt.clear();
  BsDstarTauNu_tau_fullfit_eta.clear();
  BsDstarTauNu_tau_fullfit_phi.clear();
  BsDstarTauNu_tau_fullfit_mass.clear();
  BsDstarTauNu_tau_pt.clear();
  BsDstarTauNu_tau_eta.clear();
  BsDstarTauNu_tau_phi.clear();
  BsDstarTauNu_tau_mass.clear();
  BsDstarTauNu_tau_rhomass1.clear();
  BsDstarTauNu_tau_rhomass2.clear();
  BsDstarTauNu_tau_q.clear();
  BsDstarTauNu_tau_vx.clear();
  BsDstarTauNu_tau_vy.clear();
  BsDstarTauNu_tau_vz.clear();


  BsDstarTauNu_tau_max_dr_3prong.clear();
  BsDstarTauNu_tau_lip.clear();
  BsDstarTauNu_tau_lips.clear();
  BsDstarTauNu_tau_pvip.clear();
  BsDstarTauNu_tau_pvips.clear();
  BsDstarTauNu_tau_fl3d.clear();
  BsDstarTauNu_tau_fls3d.clear();
  BsDstarTauNu_tau_alpha.clear();
  BsDstarTauNu_tau_vprob.clear();
  BsDstarTauNu_tau_isRight.clear();
  BsDstarTauNu_tau_matched_ppdgId.clear();
  BsDstarTauNu_tau_matched_gentaupt.clear();
  BsDstarTauNu_tau_sumofdnn.clear();
  BsDstarTauNu_tau_pfidx1.clear();
  BsDstarTauNu_tau_pfidx2.clear();
  BsDstarTauNu_tau_pfidx3.clear();

  BsDstarTauNu_tau_pi1_pt.clear();
  BsDstarTauNu_tau_pi1_eta.clear();
  BsDstarTauNu_tau_pi1_phi.clear();
  BsDstarTauNu_tau_pi1_mass.clear();
  BsDstarTauNu_tau_pi2_pt.clear();
  BsDstarTauNu_tau_pi2_eta.clear();
  BsDstarTauNu_tau_pi2_phi.clear();
  BsDstarTauNu_tau_pi2_mass.clear();
  BsDstarTauNu_tau_pi3_pt.clear();
  BsDstarTauNu_tau_pi3_eta.clear();
  BsDstarTauNu_tau_pi3_phi.clear();
  BsDstarTauNu_tau_pi3_mass.clear();

  BsDstarTauNu_B_pt.clear();
  BsDstarTauNu_B_eta.clear();
  BsDstarTauNu_B_phi.clear();
  BsDstarTauNu_B_mass.clear();
  BsDstarTauNu_B_vprob.clear();
  BsDstarTauNu_B_lip.clear();
  BsDstarTauNu_B_lips.clear();
  BsDstarTauNu_B_pvip.clear();
  BsDstarTauNu_B_pvips.clear();
  BsDstarTauNu_B_fl3d.clear();
  BsDstarTauNu_B_fls3d.clear();
  BsDstarTauNu_B_alpha.clear();
  BsDstarTauNu_B_maxdoca.clear();
  BsDstarTauNu_B_mindoca.clear();
  BsDstarTauNu_B_vx.clear();
  BsDstarTauNu_B_vy.clear();
  BsDstarTauNu_B_vz.clear();
  BsDstarTauNu_B_iso.clear();
  BsDstarTauNu_B_iso_ntracks.clear();
  BsDstarTauNu_B_iso_mindoca.clear();
  BsDstarTauNu_B_mm2.clear();
  BsDstarTauNu_B_q2.clear();
  BsDstarTauNu_B_Es.clear();
  BsDstarTauNu_B_ptback.clear();


  BsDstarTauNu_PV_vx.clear();
  BsDstarTauNu_PV_vy.clear();
  BsDstarTauNu_PV_vz.clear();

  BsDstarTauNu_bbPV_vx.clear();
  BsDstarTauNu_bbPV_vy.clear();
  BsDstarTauNu_bbPV_vz.clear();

  BsDstarTauNu_bbPV_refit_vx.clear();
  BsDstarTauNu_bbPV_refit_vy.clear();
  BsDstarTauNu_bbPV_refit_vz.clear();

  BsDstarTauNu_genPV_vx.clear();
  BsDstarTauNu_genPV_vy.clear();
  BsDstarTauNu_genPV_vz.clear();

  BsDstarTauNu_Ds_pt.clear();
  BsDstarTauNu_Ds_eta.clear();
  BsDstarTauNu_Ds_phi.clear();
  BsDstarTauNu_Ds_mass.clear();
  BsDstarTauNu_Ds_vprob.clear();
  BsDstarTauNu_Ds_lip.clear();
  BsDstarTauNu_Ds_lips.clear();
  BsDstarTauNu_Ds_pvip.clear();
  BsDstarTauNu_Ds_pvips.clear();
  BsDstarTauNu_Ds_fl3d.clear();
  BsDstarTauNu_Ds_fls3d.clear();
  BsDstarTauNu_Ds_alpha.clear();
  BsDstarTauNu_Ds_vx.clear();
  BsDstarTauNu_Ds_vy.clear();
  BsDstarTauNu_Ds_vz.clear();
  BsDstarTauNu_Ds_unfit_pt.clear();
  BsDstarTauNu_Ds_unfit_mass.clear();
  BsDstarTauNu_Ds_ptfrac.clear();

  BsDstarTauNu_k_charge.clear();
  BsDstarTauNu_pi_charge.clear();
  BsDstarTauNu_spi_charge.clear();

  BsDstarTauNu_D0_pt.clear();
  BsDstarTauNu_D0_eta.clear();
  BsDstarTauNu_D0_phi.clear();
  BsDstarTauNu_D0_mass.clear();
  BsDstarTauNu_D0_vprob.clear();
  BsDstarTauNu_D0_lip.clear();
  BsDstarTauNu_D0_lips.clear();
  BsDstarTauNu_D0_pvip.clear();
  BsDstarTauNu_D0_pvips.clear();
  BsDstarTauNu_D0_fl3d.clear();
  BsDstarTauNu_D0_fls3d.clear();
  BsDstarTauNu_D0_alpha.clear();
  BsDstarTauNu_D0_vx.clear();
  BsDstarTauNu_D0_vy.clear();
  BsDstarTauNu_D0_vz.clear();
  BsDstarTauNu_D0_unfit_pt.clear();
  BsDstarTauNu_D0_unfit_mass.clear();
  BsDstarTauNu_D0_ptfrac.clear();

  BsDstarTauNu_ngenmuons.clear();

  BsDstarTauNu_isgen3.clear();
  BsDstarTauNu_isgen3matched.clear();
  BsDstarTauNu_nch.clear();
  BsDstarTauNu_nch_after_dnn.clear();
  BsDstarTauNu_nch_before_dnn.clear();
  BsDstarTauNu_nch_qr.clear();
  BsDstarTauNu_ngentau3.clear();
  BsDstarTauNu_ngentau.clear();
  BsDstarTauNu_gentaupt.clear();
  BsDstarTauNu_gentaudm.clear();


  //change
  /*
  allParticle_N.clear();
  allParticle_charge.clear();
  allParticle_pt.clear();
  allParticle_eta.clear();
  allParticle_phi.clear();
  allParticle_dxy.clear();
  allParticle_dz.clear();
  allParticle_exy.clear();
  allParticle_ez.clear();
  */



  ////////////////////////


 
} 


void NtupleBranches::LabelHistograms( std::map< std::string, bool >& runFlags ){
  //  if ( runFlags["doCutFlow"] ){
    std::vector bins_string = {"Precut", "Trigger","muons", "J/#psi", "J/#psi fit","Tau  presence"};
    for(size_t i=0; i< bins_string.size(); i++){
      cutflow_perevt->GetXaxis()->SetBinLabel(i+1, bins_string[i]);
    }
    //  }


  if ( runFlags["doGenHist"] ){
    std::vector bins_string = { "#mu", "#pi^{0}", "#pi^{#pm}","#rho^{0}","#rho^{#pm}","#eta","#eta^{`}","#omega","#phi","K^{0}","K^{#pm}","K^{*0}","K^{*#pm}","D^{#pm}","D^{0}","#eta_{c}","#eta_{b}","#Upsilon"};
    for(size_t i=0; i< bins_string.size(); i++){
      genParticle_Bdau_X_id->GetXaxis()->SetBinLabel(i+1, bins_string[i]);
    }       
  }
}
