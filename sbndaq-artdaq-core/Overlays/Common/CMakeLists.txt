cet_make_library( LIBRARY_NAME sbndaq-artdaq-core_Overlays_Common_Utilities
		  SOURCE 
		  Utilities.cc
		  LIBRARIES
		  ${ARTDAQ_DAQDATA}
			${ARTDAQ-CORE_UTILITIES}
		  ${CETLIB}
		  ${CETLIB_EXCEPT}
                  ${Boost_SYSTEM_LIBRARY}
                  ${MF_MESSAGELOGGER}
                  ${MF_UTILITIES}
)

cet_make_library( LIBRARY_NAME sbndaq-artdaq-core_Overlays_Common
		  SOURCE 
		  CAENV1730Fragment.cc
		  SpectratimeEventFragment.cc
		  BernCRTZMQFragment.cc
		  BernCRTFragment.cc
		  DummyFragment.cc
		  LIBRARIES
		  ${ARTDAQ_DAQDATA}
			${ARTDAQ-CORE_UTILITIES}
		  ${CETLIB}
		  ${CETLIB_EXCEPT}
)

install_headers()
install_source()
