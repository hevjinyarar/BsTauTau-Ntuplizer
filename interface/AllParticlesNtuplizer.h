#ifndef AllParticlesNtuplizer_H
#define AllParticlesNtuplizer_H

#include "../interface/CandidateNtuplizer.h"
//#include "PhysicsTools/HepMCCandAlgos/interface/GenParticlesHelper.h"
//#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include <algorithm>
#include <vector>


class AllParticlesNtuplizer : public CandidateNtuplizer {

public:
  //AllParticlesNtuplizer( std::vector<edm::EDGetTokenT<pat::PackedCandidateCollection>> tokens,
  AllParticlesNtuplizer( edm::EDGetTokenT<pat::PackedCandidateCollection> packedpfcandidatesToken,  
			 NtupleBranches* nBranches, std::map< std::string, bool >&  runFlags );

  ~AllParticlesNtuplizer( void ); 

  //void fillBranches( edm::Event const & event, const edm::EventSetup& iSetup  );
  //void fillBranches_AllParticles( edm::Event const & event, const edm::EventSetup& iSetup  );
  bool fillBranches( edm::Event const & event, const edm::EventSetup& iSetup  );

private:
   edm::EDGetTokenT<pat::PackedCandidateCollection> packedpfcandidatesToken_;
   edm::Handle< pat::PackedCandidateCollection >  allParticles_;
   bool verbose_;

};

#endif // AllParticlesNtuplizer_H
