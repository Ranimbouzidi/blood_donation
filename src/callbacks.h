#include <gtk/gtk.h>

int argc;
char *argv[];

void
on_R1_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajouter_ranim_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_R2_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_EXIT_ranim_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_B4_clicked                          (GtkButton       *button,
                                        gpointer         user_data);

void
on_R3_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_R4_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_B5_clicked                          (GtkButton       *button,
                                        gpointer         user_data);

void
on_supp_rann_clicked                   (GtkButton       *button,
                                        gpointer         user_data);


void
on_aff_his_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_historique_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_res_rdv_clicked              (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_button_res_rdv_destroy_event        (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_histo_win_disp_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_theme_btn_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_statistique_btn_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_theme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_theme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_theme_btn_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiostat2_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiostat1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_B10_clicked                         (GtkButton       *button,
                                        gpointer         user_data);



void
on_treeviewGD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_GDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDTraiteStatusAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDCoursStatusAjout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDnonUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDouiUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDouiUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDnonUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDTraiteStatusModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDCoursStatusModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDModifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDsearchModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_GDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data);
