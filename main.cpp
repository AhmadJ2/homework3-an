
#include "igl/opengl/glfw/renderer.h"
#include "tutorial/sandBox/inputManager.h"
#include "sandBox.h"

static void drawDotsAndLines(igl::opengl::glfw::Viewer& viewer) {

	for (int i = 1; i <= 5; i++) {

		int savedIndx = viewer.selected_data_index;
		viewer.load_mesh_from_file("C:/Dev/EngineForAnimationCourse/tutorial/data/zcylinder.obj");
		if (viewer.data_list.size() > viewer.parents.size())
		{
			viewer.parents.push_back(-1);
			viewer.data_list.back().set_visible(false, 1);
			viewer.data_list.back().set_visible(true, 2);
			viewer.selected_data_index = savedIndx;
			//Ass3
			if(i!=1) 
			{ 
				int last_index = viewer.data_list.size() - 1;
				viewer.parents[last_index] = last_index - 1;
			 }
			//end Ass3
		}
	}
}



int main(int argc, char *argv[])
{
  Display *disp = new Display(1200, 800, "Wellcome");
  Renderer renderer;

  SandBox viewer;
  igl::opengl::glfw::imgui::ImGuiMenu* menu = new igl::opengl::glfw::imgui::ImGuiMenu();
  viewer.Init("configuration.txt");
   

  for (int i = 0; i < viewer.data_list.size(); i++) {
	  viewer.data_list[i].tree.init(viewer.data_list[i].V, viewer.data_list[i].F);
  }
 
  drawDotsAndLines(viewer);
 
  Init(*disp, menu);
  renderer.init(&viewer,2,menu);
  disp->SetRenderer(&renderer);

  disp->launch_rendering(true);
  delete menu;
  delete disp;
}
