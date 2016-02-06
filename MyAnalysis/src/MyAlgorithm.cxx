// MyAnalysis includes
#include "MyAlgorithm.h"
#include <AsgTools/MessageCheck.h>



MyAlgorithm::MyAlgorithm( const std::string& name, ISvcLocator* pSvcLocator ) : AthHistogramAlgorithm( name, pSvcLocator ){

  //declareProperty( "Property", m_nProperty ); //example property declaration

}


MyAlgorithm::~MyAlgorithm() {}


StatusCode MyAlgorithm::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");


  ANA_CHECK (book (TH1D ("met", "MET spectrum", 100, 0, 1000e3)));

  return StatusCode::SUCCESS;
}

StatusCode MyAlgorithm::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode MyAlgorithm::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");

  // fill the MET histogram with a dummy value of 42 GeV
  hist("met")->Fill (42e3);

  return StatusCode::SUCCESS;
}


