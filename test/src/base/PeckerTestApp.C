//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "PeckerTestApp.h"
#include "PeckerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
PeckerTestApp::validParams()
{
  InputParameters params = PeckerApp::validParams();
  return params;
}

PeckerTestApp::PeckerTestApp(InputParameters parameters) : MooseApp(parameters)
{
  PeckerTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

PeckerTestApp::~PeckerTestApp() {}

void
PeckerTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  PeckerApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"PeckerTestApp"});
    Registry::registerActionsTo(af, {"PeckerTestApp"});
  }
}

void
PeckerTestApp::registerApps()
{
  registerApp(PeckerApp);
  registerApp(PeckerTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
PeckerTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PeckerTestApp::registerAll(f, af, s);
}
extern "C" void
PeckerTestApp__registerApps()
{
  PeckerTestApp::registerApps();
}
