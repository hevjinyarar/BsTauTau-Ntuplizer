#include "../interface/AllParticlesNtuplizer.h"
 
//===================================================================================================================        
//AllParticlesNtuplizer::AllParticlesNtuplizer( std::vector<edm::EDGetTokenT<pat::PackedCandidateCollection>> tokens, NtupleBranches* nBranches, std::map< std::string, bool >& runFlags ) 
AllParticlesNtuplizer::AllParticlesNtuplizer( edm::EDGetTokenT<pat::PackedCandidateCollection> packedpfcandidatesToken, NtupleBranches* nBranches, std::map< std::string, bool >& runFlags ) 


   : CandidateNtuplizer( nBranches )
   //, allParticlesToken_( tokens[0] )
   , packedpfcandidatesToken_( packedpfcandidatesToken )
   , verbose_   (runFlags["verbose"])
{

}

//===================================================================================================================        
AllParticlesNtuplizer::~AllParticlesNtuplizer( void )
{
}


//===================================================================================================================        
//void AllParticlesNtuplizer::fillBranches_AllParticles( edm::Event const & event, const edm::EventSetup& iSetup ){
bool AllParticlesNtuplizer::fillBranches( edm::Event const & event, const edm::EventSetup& iSetup ){  

    event.getByToken(packedpfcandidatesToken_ , allParticles_); 

    unsigned int nPFC = 
    nBranches_->allParticle_N = allParticles_->size();
    auto& allPFC = *allParticles_;
    nBranches_->allParticle_charge.resize( nPFC );
    nBranches_->allParticle_pt.resize( nPFC );
    nBranches_->allParticle_eta.resize( nPFC );
    nBranches_->allParticle_phi.resize( nPFC );
    nBranches_->allParticle_dxy.resize( nPFC );
    nBranches_->allParticle_dz.resize( nPFC );
    nBranches_->allParticle_exy.resize( nPFC );
    nBranches_->allParticle_ez.resize( nPFC );
    for( unsigned p=0; p<nPFC; ++p ){
      const pat::PackedCandidate& pp = allPFC[p];
      nBranches_->allParticle_charge[p] = pp.charge();
      nBranches_->allParticle_pt [p] = pp.pt();
      nBranches_->allParticle_eta[p] = pp.eta();
      nBranches_->allParticle_phi[p] = pp.phi();
      if ( pp.hasTrackDetails() ) {
        const reco::Track& trk = pp.pseudoTrack();
        nBranches_->allParticle_dxy[p] = trk.dxy();
        nBranches_->allParticle_dz [p] = trk.dz ();
        nBranches_->allParticle_exy[p] = trk.dxyError();
        nBranches_->allParticle_ez [p] = trk.dzError ();
      }
    }

    return true;
}

