#include"JProject.h"
#include"ProjectContext.h"

ProjectContext::ProjectContext(JProject *definingProject) : Context("ProjectContext", 0, 0, 0, 0)
{

	this->projectContext = this;
	this->definingProject = definingProject;
}
