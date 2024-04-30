#ifndef GUARD_PAIRSELECTION_H
#define GUARD_PAIRSELECTION_H

#include "ROOT/RDataFrame.hxx"
#include "ROOT/RVec.hxx"
#include "TVector2.h"
#include "bitset"
#include "utility/Logger.hxx"
#include "utility/utility.hxx"

typedef std::bitset<15> StatusBits;
struct GenParticle {
    int index;
    int status;
    std::bitset<15> statusflag;
    int pdgid;
    int motherid;
};
bool check_mother(ROOT::RVec<GenParticle> genparticles, const int index,
                  const int mother_pdgid);

namespace pairselection {
ROOT::RDF::RNode buildgenpair(ROOT::RDF::RNode df, const std::string &recopair,
                              const std::string &genindex_particle1,
                              const std::string &genindex_particle2,
                              const std::string &genpair);
ROOT::RDF::RNode
buildtruegenpair(ROOT::RDF::RNode df, const std::string &statusflags,
                 const std::string &status, const std::string &pdgids,
                 const std::string &motherids, const std::string &pts,
                 const std::string &genpair, const int mother_pdgid,
                 const int daughter_1_pdgid, const int daughter_2_pdgid);
ROOT::RDF::RNode flagGoodPairs(ROOT::RDF::RNode df, const std::string &flagname,
                               const std::string &pairname);
auto compareForPairs(const ROOT::RVec<float> &lep1pt,
                     const ROOT::RVec<float> &lep1iso,
                     const ROOT::RVec<float> &lep2pt,
                     const ROOT::RVec<float> &lep2iso);
ROOT::RDF::RNode findAdditionalTau(ROOT::RDF::RNode df, const std::string &outputname, 
                                   const std::string &tau_mask, const std::string &pairname);
}// end namespace pairselection

namespace ditau_pairselection {
namespace semileptonic {
auto PairSelectionAlgo(const float &mindeltaR);
} // end namespace semileptonic

namespace fullhadronic {
auto PairSelectionAlgo(const float &mindeltaR);
} // end namespace fullhadronic

// namespace for full leptonic pairselection
namespace leptonic {
auto ElMuPairSelectionAlgo(const float &mindeltaR);
auto PairSelectionAlgo(const float &mindeltaR);
auto PairSelectionAlgoOSPreferred(const float &mindeltaR);
auto ZBosonPairSelectionAlgo(const float &mindeltaR);
auto ZBosonPairSelectionAlgoOSPreferred(const float &mindeltaR);
} // end namespace leptonic
namespace mutau {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR);
} // end namespace mutau

namespace eltau {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR);
} // end namespace eltau

namespace tautau {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR);

} // end namespace tautau

namespace elmu {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR);
} // end namespace elmu

namespace mumu {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR);

ROOT::RDF::RNode PairSelectionOSPreferred(ROOT::RDF::RNode df,
                        const std::vector<std::string> &input_vector,
                        const std::string &pairname, const float &mindeltaR);

ROOT::RDF::RNode
ZBosonPairSelection(ROOT::RDF::RNode df,
                    const std::vector<std::string> &input_vector,
                    const std::string &pairname, const float &mindeltaR);

ROOT::RDF::RNode ZBosonPairSelectionOSPreferred(
           ROOT::RDF::RNode df, const std::vector<std::string> &input_vector,
           const std::string &pairname, const float &mindeltaR);

} // end namespace mumu
namespace elel {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR);

ROOT::RDF::RNode
ZBosonPairSelection(ROOT::RDF::RNode df,
                    const std::vector<std::string> &input_vector,
                    const std::string &pairname, const float &mindeltaR);
} // end namespace elel
} // end namespace ditau_pairselection

namespace boosted_ditau_pairselection {
auto compareForPairs(const ROOT::RVec<float> &lep1pt, const ROOT::RVec<float> &lep1eta, const ROOT::RVec<float> &lep1phi, const ROOT::RVec<float> &lep1mass,
                     const ROOT::RVec<float> &lep2pt, const ROOT::RVec<float> &lep2eta, const ROOT::RVec<float> &lep2phi, const ROOT::RVec<float> &lep2mass);
namespace semileptonic {
auto PairSelectionAlgo(const float &mindeltaR, const float &maxdeltaR);
} // end namespace semileptonic
namespace fullhadronic {
auto PairSelectionAlgo(const float &mindeltaR, const float &maxdeltaR);
} // end namespace fullhadronic
namespace mutau {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR, const float &maxdeltaR);
} // end namespace mutau
namespace eltau {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR, const float &maxdeltaR);
} // end namespace mutau
namespace tautau {

ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR, const float &maxdeltaR);
} // end namespace tautau
} // end namespace boosted_ditau_pairselection

namespace bb_pairselection {
auto BBPairSelectionAlgo(const float &mindeltaR, const float &btag_WP_value);
ROOT::RDF::RNode PairSelection(ROOT::RDF::RNode df,
                               const std::vector<std::string> &input_vector,
                               const std::string &pairname,
                               const float &mindeltaR,
                               const float &btag_WP_value);
} // end namespace bb_pairselection
#endif /* GUARD_PAIRSELECTION_H */
