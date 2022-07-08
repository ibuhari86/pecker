#include "PeckerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
PeckerApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

PeckerApp::PeckerApp(InputParameters parameters) : MooseApp(parameters)
{
  PeckerApp::registerAll(_factory, _action_factory, _syntax);
}

PeckerApp::~PeckerApp() {}

void
PeckerApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"PeckerApp"});
  Registry::registerActionsTo(af, {"PeckerApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
PeckerApp::registerApps()
{
  registerApp(PeckerApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
PeckerApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PeckerApp::registerAll(f, af, s);
}
extern "C" void
PeckerApp__registerApps()
{
  PeckerApp::registerApps();
}
