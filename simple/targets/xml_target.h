#ifndef __SIMPLE_SEMANTICS_XML_TARGET_H__
#define __SIMPLE_SEMANTICS_XML_TARGET_H__

#include <cdk/basic_target.h>
#include <cdk/compiler.h>
#include "targets/xml_writer.h"

namespace simple {

  class xml_target: public cdk::basic_target {
    static xml_target _self;

  private:
    xml_target() :
        cdk::basic_target("xml") {
    }

  public:
    bool evaluate(std::shared_ptr<cdk::compiler> compiler) {
      // this symbol table will be used to check identifiers
      // an exception will be thrown if identifiers are used before declaration
      cdk::symbol_table<simple::symbol> symtab;

      xml_writer writer(compiler, symtab);
      compiler->ast()->accept(&writer, 0);
      return true;
    }

  };

} // simple

#endif
