#pragma once
#include"Context.h"
class JProject;

class ProjectContext : public Context
{
	
public:
	JProject *definingProject;
	ProjectContext(JProject *);
};

