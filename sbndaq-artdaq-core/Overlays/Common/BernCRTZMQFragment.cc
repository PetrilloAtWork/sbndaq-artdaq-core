#include "sbndaq-artdaq-core/Overlays/Common/BernCRTZMQFragment.hh"
#include <iostream>

#include "cetlib_except/exception.h"

std::ostream & sbndaq::operator << (std::ostream & os, BernCRTZMQFragmentMetadata const& m){
  os << "BernCRTZMQFragmentMetadata:"
     << "\n\tRun start time:   " << sbndaq::BernCRTZMQFragment::print_timestamp(m.run_start_time())
     << "\n\tLast poll start:  " << sbndaq::BernCRTZMQFragment::print_timestamp(m.last_poll_start())
     << "\n\tLast poll finish: " << sbndaq::BernCRTZMQFragment::print_timestamp(m.last_poll_end())
     << "\n\tThis poll start:  " << sbndaq::BernCRTZMQFragment::print_timestamp(m.this_poll_start())
     << "\n\tThis poll finish: " << sbndaq::BernCRTZMQFragment::print_timestamp(m.this_poll_end())
     << "\n\tNumber of events for this FEB in a poll: " << m.feb_events_per_poll()
     << "\n\tEvent number for this FEB: " << m.feb_event_number();
  os << std::endl;
  return os;
}

std::ostream & sbndaq::operator << (std::ostream & os, BernCRTZMQEvent const & e){
  os << "\nBernCRTZMQEvent"
     << "\n\tMAC5: 0x" << std::hex << e.MAC5() << std::dec;
  os << "\n\tLostCPU: " << e.lostcpu;
  os << "\n\tLostFPGA: " << e.lostfpga;
  os << "\n\tTime1 (TS0): " << sbndaq::BernCRTZMQFragment::print_timestamp(e.Time_TS0());
  os << "\n\tTime2 (TS1): " << sbndaq::BernCRTZMQFragment::print_timestamp(e.Time_TS1());
  for(size_t i_c=0; i_c<32; ++i_c) {
    os << " adc["<<i_c<<"]: " << e.ADC(i_c) << " ";
  }
  os << std::endl;
  return os;
}

  os << "BernCRTZMQFragment: "
  return os;

  bool verified=true;

  if(metadata()->n_events()*sizeof(BernCRTZMQEvent) != DataPayloadSize() )
    verified = false;

  return verified;
    

std::string sbndaq::BernCRTZMQFragment::print_timestamp(uint64_t t) {
  char s[43];
  if(t >= (uint64_t)10*1000*1000*1000) {
    sprintf(s, "%lu %03lu %03lu %03lu.%03lu %03lu %03lu [s.ns]",
      (t/1000000000000000000) %1000,
      (t/1000000000000000)    %1000,
      (t/1000000000000)       %1000,
      (t/1000000000)          %1000,
      (t/1000000)             %1000,
      (t/1000)                %1000,
      (t)                     %1000
    );
  }
  else {
    sprintf(s, "            %lu.%03lu %03lu %03lu [s.ns]",
      (t/1000000000)          %1000,
      (t/1000000)             %1000,
      (t/1000)                %1000,
      (t)                     %1000
    );
  }
  return s;
}

/*
std::string sbndaq::BernCRTZMQEvent::db_entry() const {

  std::stringstream ss_tags,ss_data;
  ss_tags << "time1_ref=" << time1.IsReference() << ",";
  ss_tags << "time2_ref=" << time2.IsReference() << ",";
  ss_tags << "time1_ovfl=" << time1.IsOverflow() << ",";
  ss_tags << "time2_ovfl=" << time2.IsOverflow() << ",";

  ss_data << "overwritten=" << flags.overwritten << ",";
  ss_data << "missed=" << flags.missed << ",";
  ss_data << "time1=" << time1.Time() << ",";
  ss_data << "time2=" << time2.Time() << ",";
  for(size_t i=0; i<32; ++i)
    ss_data << "ch" << i << "=" << adc[i] << ",";


  return (ss_tags.str()+" "+ss_data.str());
}
*/
