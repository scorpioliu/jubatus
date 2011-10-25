// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011 Preferred Infrastracture and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once
#include <string>
namespace jubatus{

  // child process
  class process{
  public:
    process(const std::string& zkhosts, const std::string& logfile = "/dev/null");
    ~process();

    bool set_names(const std::string&);
    bool spawn_link(int);
    bool kill();

    bool has_samespec(const process&) const ;

    const std::string& get_name() const { return name_; };
    const std::string& get_type() const { return type_; };
    const std::string& get_storage() const { return storage_; };
    int get_rpc_port()const {return rpc_port_;};
  private:
    std::string type_;
    std::string name_;
    std::string storage_;
    std::string zk_hosts_;
    std::string logfile_;
    int rpc_port_;
    int pid_;
  };

}
