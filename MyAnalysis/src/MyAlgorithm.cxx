// MyAnalysis includes
#include "MyAlgorithm.h"
#include <AsgTools/MessageCheck.h>



MyAlgorithm::MyAlgorithm( const std::string& name, ISvcLocator* pSvcLocator ) : AthHistogramAlgorithm( name, pSvcLocator ){
  declareProperty ("quickAna", quickAna);
}

MyAlgorithm::~MyAlgorithm() {
}


StatusCode MyAlgorithm::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");

  ANA_CHECK (book (TH1D ("el_num", "electron multiplicity", 10, 0, 10)));
  ANA_CHECK (book (TH1D ("el_pt", "electron transverse momentum", 100, 0, 500e3)));

  return StatusCode::SUCCESS;
}

StatusCode MyAlgorithm::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode MyAlgorithm::execute() {
  ATH_MSG_INFO ("Executing " << name() << "...");
  ANA_CHECK (quickAna->process ());


  unsigned el_num = 0;
  for (auto electron : *quickAna->electrons())
  {
    if (electron->auxdata<ana::SelectType> ("ana_select")) {
      ++el_num;
      hist("el_pt")->Fill (electron->pt(), quickAna->weight());
    }
  }
  hist("el_num")->Fill (el_num, quickAna->weight());

  return StatusCode::SUCCESS;
}
