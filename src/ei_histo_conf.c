#include "ei_historique_configuration.h"
#include <stdlib.h>

void initialize_history(void){
    historique_configuration= calloc(1,sizeof (ei_historique_configuration_t));
    historique_configuration->histo_frame=calloc(1,sizeof (ei_historique_frame_t));
    historique_configuration->histo_button=calloc(1,sizeof (ei_historique_button_t));
    historique_configuration->histo_toplevel=calloc(1,sizeof (ei_historique_toplevel_t ));
}