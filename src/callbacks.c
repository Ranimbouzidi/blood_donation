#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "rdvranim.h"
#include <stdlib.h>
#include <stdio.h>
#include "gestionDemande.h"
int urgence1 ;
int status1;
int urgence2;
int status2;

void
on_treeviewGD_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   
}


void
on_GDdeconnexcion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
     
}


void
on_GDstatistiqueWidget_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDstatistique,*GDaffiche;
     GDstatistique = lookup_widget(button,"GDstatistique");
      gtk_widget_destroy(GDstatistique);
     GDstatistique = lookup_widget(button,"GDstatistique");
     GDstatistique = create_GDstatistique();
     gtk_widget_show(GDstatistique);

}


void
on_GDactualiser_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDaffiche,*w1,*treeview;
      w1=lookup_widget(button,"GDaffiche");
      GDaffiche=create_GDaffiche();
       gtk_widget_show(GDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview,"eya.txt");

}


void
on_GDsupprimerWidget_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDsupprime,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDsupprime = lookup_widget(button,"GDsupprime");
     GDsupprime = create_GDsupprime();
     gtk_widget_show(GDsupprime);
}


void
on_GDmodifierWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *GDmodife,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDmodife = lookup_widget(button,"GDmodife");
     GDmodife = create_GDmodife();
     gtk_widget_show(GDmodife);
}


void
on_GDajoutWidget_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDajoute,*GDaffiche;
     GDaffiche = lookup_widget(button,"GDaffiche");
      gtk_widget_destroy(GDaffiche);
     GDajoute = lookup_widget(button,"GDajoute");
     GDajoute = create_GDajoute();
     gtk_widget_show(GDajoute);
}


void
on_GDsearchButton_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *id ,*GDaffiche,*pInfo,*w1,*treeview;
    
           int b = 1;
         char id1[50];
         GDaffiche  = lookup_widget(button,"GDaffiche");
           GDaffiche = create_GDaffiche();
        id = lookup_widget(button,"GDsearchEntry"); 
        
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
            pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
             }else{
                w1=lookup_widget(button,"GDaffiche");
      GDaffiche=create_GDaffiche();
       gtk_widget_show(GDaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       rechercherDemande(treeview,"eya.txt",id1);

           }
}


void
on_GDsupprimerButton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDsupprime,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
   char id1[50];
   GDsupprime = lookup_widget(button,"GDsupprime");
           GDsupprime = create_GDsupprime();
   id = lookup_widget(button,"GDidEntrySupprimer"); 
    label = lookup_widget(button,"GDcontroleSaisiSupprimer");
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
        if(strcmp(id1,"")==0 ){
      
           b=0;
             }
                            if(b == 1){
       int t =  supprimerDemande("eya.txt",id1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Supprimer Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDsupprime);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview, "eya.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed Supprimer  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
   
}


void
on_GDannulerSupprimerButton_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDsupprime,*GDaffiche;
     GDsupprime = lookup_widget(button,"GDsupprime");
   gtk_widget_destroy(GDsupprime);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDannulerAjoutButton_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *GDajoute,*GDaffiche;
     GDajoute = lookup_widget(button,"GDajoute");
   gtk_widget_destroy(GDajoute);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}

void
on_GDTraiteStatusAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status1=2;} 
}


void
on_GDCoursStatusAjout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(togglebutton))
 {status1=1;} 
}  


void
on_GDnonUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence1=2;} 
}


void
on_GDouiUrgenceAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence1=1;} 
}


void
on_GDajoutButton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDajoute,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
  Demande d;
   GDajoute = lookup_widget(button,"GDajoute");
           GDajoute = create_GDajoute();
   id = lookup_widget(button,"GDidEntryAjout"); 
 etab= lookup_widget(button,"GDetabComboAjout1");
 jj =  lookup_widget(button,"GDjjSpinAjout");
        mm =  lookup_widget(button,"GDmmSpinAjout");
        yy =   lookup_widget(button,"GDyySpinAjout");
        quantite = lookup_widget(button,"GDquantiteSpinAjout");
        sangType =  lookup_widget(button,"GDtypeSangComboAjout1");
        label = lookup_widget(button,"GDcontroleSaisiAjout");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
         d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sangType)));
         if(urgence1 == 1){
          strcpy(d.urgence,"oui");
         }else{
         strcpy(d.urgence,"non");
         }
          if(status1 == 1){
          strcpy(d.status,"encours");
         }else {
         strcpy(d.status,"traite");
         }
          if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
               if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

                         if(b == 1){
       int t =  ajouterDemande("eya.txt",d);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDajoute);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview, "eya.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


           
}



void
on_GDannulerModifierButton_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *GDmodife,*GDaffiche;
     GDmodife = lookup_widget(button,"GDmodife");
   gtk_widget_destroy(GDmodife);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDouiUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence2=1;}
}


void
on_GDnonUrgenceModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{urgence2=2;}
}


void
on_GDTraiteStatusModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status2=2;}
}


void
on_GDCoursStatusModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(togglebutton))
 {status2=1;}
}


void
on_GDModifierButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*etab,*quantite,*jj,*mm,*yy,*sangType,*GDmodife,*label,*pInfo,*GDaffiche,*w1,*treeview;
  int b = 1;
  Demande d;
   GDmodife = lookup_widget(button,"GDmodife");
           GDmodife = create_GDmodife();
   id = lookup_widget(button,"GDidEntryModifier"); 
 etab= lookup_widget(button,"GDetabComboModifier1");
 jj =  lookup_widget(button,"GDjjSpinModifier");
        mm =  lookup_widget(button,"GDmmSpinModifier");
        yy =   lookup_widget(button,"GDyySpinModifier");
        quantite = lookup_widget(button,"GDquantiteSpinModifier");
        sangType =  lookup_widget(button,"GDtypeSangComboModifier1");
        label = lookup_widget(button,"GDcontroleSaisiModifier");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
         strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
         d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sangType)));
         if(urgence2 == 1){
          strcpy(d.urgence,"oui");
         }else{
         strcpy(d.urgence,"non");
         }
          if(status2 == 1){
          strcpy(d.status,"encours");
         }else {
         strcpy(d.status,"traite");
         }
          if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
               if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

                         if(b == 1){
       int t =  modifierDemande("eya.txt",d.id,d);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modifier  Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(GDmodife);
              GDaffiche = lookup_widget(button,"GDaffiche");
             GDaffiche = create_GDaffiche();
             gtk_widget_show(GDaffiche);
                 w1=lookup_widget(button,"GDaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(GDaffiche,"treeviewGD");
       viderDemande(treeview);
       afficherDemande(treeview, "eya.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed Modification  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


}


void
on_GDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *label;
   label = lookup_widget(button,"GDtypePlusDemandeLabelStatistique");
    gtk_label_set_text(GTK_LABEL(label),afficherTypeSangPlusDemande("eya.txt"));
}


void
on_GDannulerStatistiqueButton_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *GDstatistique,*GDaffiche;
     GDstatistique = lookup_widget(button,"GDstatistique");
   gtk_widget_destroy(GDstatistique);
     GDaffiche = lookup_widget(button,"GDaffiche");
     GDaffiche = create_GDaffiche();
     gtk_widget_show(GDaffiche);
}


void
on_GDsearchModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_GDstatistiqueButton1_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget  *etab,*label1,*labelControlle,*GDstatistique;
      GDstatistique = lookup_widget(button,"GDstatistique");
           GDstatistique = create_GDstatistique();
    int b=1;
char etab1[50];
   etab = lookup_widget(button,"GDcomboEtabStatistique"); 
   label1 = lookup_widget(button,"GDpourcentageDemandeLabelStatistique");
    labelControlle = lookup_widget(button,"GDcontroleSaisiStatistique"); 
    strcpy(etab1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        if(strcmp(etab1,"")==0 ){
      
           b=0;
             }
         if (b == 1){
       float pourcentage = afficherPourcentageDemandes("eya.txt",etab1);
       char var[50];
    sprintf(var,"%.2f",pourcentage);

         gtk_label_set_text(GTK_LABEL(label1),var);


         }else{


           gtk_label_set_text(GTK_LABEL(labelControlle),"verifier vos donnée ❌️");

        }
     
}

//-----------------------------------------------------Ranim----------------------------------------------------------------
int r=1;

char img1[30]="B.jpg";


void chang_background(GtkWidget *widget,int w,int h,const gchar *path)
{
gtk_widget_set_app_paintable(widget,TRUE);
gtk_widget_realize(widget);
gtk_widget_queue_draw(widget);

GdkPixbuf *src_pixbuf=gdk_pixbuf_new_from_file(path,NULL);
GdkPixbuf*dst_pixbuf=gdk_pixbuf_scale_simple(src_pixbuf,w,h,GDK_INTERP_BILINEAR);

GdkPixmap *pixmap=NULL;
gdk_pixbuf_render_pixmap_and_mask(dst_pixbuf,&pixmap,NULL,128);
gdk_window_set_back_pixmap(widget->window,pixmap,FALSE);

g_object_unref(src_pixbuf);
g_object_unref(dst_pixbuf);
g_object_unref(pixmap);

}



void
on_R1_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
  r=1;
}


void
on_ajouter_ranim_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
rendezvous rdv;
    char ID[50];
    
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11,*err_cin,*err_prenom,*err_nom, *valid_msg;

    input1 = lookup_widget(GTK_WIDGET(button), "nom");
    input2 = lookup_widget(GTK_WIDGET(button), "prenom");
    input3 = lookup_widget(GTK_WIDGET(button), "comboA");
    input4 = lookup_widget(GTK_WIDGET(button),  "entryid");
    input5 = lookup_widget(GTK_WIDGET(button), "combo1");
    input6 = lookup_widget(GTK_WIDGET(button), "combo2");
    input7 = lookup_widget(GTK_WIDGET(button), "S1");
    input8 = lookup_widget(GTK_WIDGET(button), "S2");
    input9= lookup_widget(GTK_WIDGET(button), "S3");
    input10= lookup_widget(GTK_WIDGET(button), "R1");
    input11= lookup_widget(GTK_WIDGET(button), "R2");
    

    
     rdv.date.jours= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
     rdv.date.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
     rdv.date.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
    strcpy(rdv.donneurs.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(rdv.donneurs.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(ID, gtk_entry_get_text(GTK_ENTRY(input4)));
   rdv.idrdv=atoi(ID);

	err_cin=lookup_widget(GTK_WIDGET (button),"err_cin");
	err_nom=lookup_widget(GTK_WIDGET (button),"err_nom");
	err_prenom=lookup_widget(GTK_WIDGET (button),"err_prenom");
	valid_msg=lookup_widget(GTK_WIDGET (button),"valid_msg");

char ide[20];
sprintf(ide,"%d",rdv.idrdv);

if((strlen(ID)!=8))
{
gtk_label_set_markup(GTK_LABEL(err_cin),"<b><span color='red'>*Cin non valide !! </span></b>");

}
else if(strlen(rdv.donneurs.nom)==0)
{
gtk_label_set_markup(GTK_LABEL(err_nom),"<b><span color='red'>*vérifier vos infos !! </span></b>");
gtk_label_set_markup(GTK_LABEL(err_cin),"");
}
else if(strlen(rdv.donneurs.prenom)==0)
{
gtk_label_set_markup(GTK_LABEL(err_prenom),"<b><span color='red'>*vérifier vos infos !! </span></b>");
gtk_label_set_markup(GTK_LABEL(err_nom),"");
}
else
{

if(strcmp("tunis",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)))==0)
       strcpy(rdv.etablissement.region,"tunis");
else if (strcmp("ariana",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)))==0)
       {
       strcpy(rdv.etablissement.region,"ariana");}

if(strcmp("ETS1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)))==0)
       strcpy(rdv.etablissement.nometablisssement,"ETS1");
else if (strcmp("ETS2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)))==0)
       {
       strcpy(rdv.etablissement.nometablisssement,"ETS2");}
else if (strcmp("ETS3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)))==0)
       {
       strcpy(rdv.etablissement.nometablisssement,"ETS3");
}
if(strcmp("A+",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)))==0)
       strcpy(rdv.donneurs.groupesanguine,"A+");
else if (strcmp("A-",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)))==0)
       {
       strcpy(rdv.donneurs.groupesanguine,"A-");}
else if (strcmp("O+",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)))==0)
       {
       strcpy(rdv.donneurs.groupesanguine,"O+");}

if(r==1) {
        strcpy(rdv.time,"matin") ; }
  if(r==2){
        strcpy(rdv.time,"apresmidi") ;}

   int X=ajouter(rdv, "rendezvous.txt");

gtk_label_set_markup(GTK_LABEL(valid_msg),"<b><span color='green'>* ajouté avec succés  </span></b>");
}
}


void
on_R2_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
  r=2;
}


void
on_EXIT_ranim_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_B4_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
char cinm[20] ;
  GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9 ;

    input1 = lookup_widget(GTK_WIDGET(button), "id_modif");
    input2 = lookup_widget(GTK_WIDGET(button), "S4");
    input3 = lookup_widget(GTK_WIDGET(button), "S5");
    input4 = lookup_widget(GTK_WIDGET(button), "S6");
    input5 = lookup_widget(GTK_WIDGET(button),"combo3");
    input6 = lookup_widget(GTK_WIDGET(button),"combo4");
    input7 = lookup_widget(GTK_WIDGET(button),"R3");
    input8 = lookup_widget(GTK_WIDGET(button),"R4");
    input9 = lookup_widget(GTK_WIDGET (button),"modif");
	strcpy(cinm,gtk_entry_get_text(GTK_ENTRY(input1)));
	int cinx= atoi(cinm);
	rendezvous rdv=chercher(cinx ,"rendezvous.txt");
	
	if (rdv.idrdv==-1) {
			gtk_label_set_markup(GTK_LABEL(input9),"<b><span color='orange'>*CIN NON EXISTANT !</span></b>");
		}
	else {
		gtk_label_set_markup(GTK_LABEL(input9),"<b><span color='blue'>*Tapez vos nouveaux données ! </span></b>");
       		
        	gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2), rdv.date.jours);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), rdv.date.mois);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4), rdv.date.annee);
		}		

}


void
on_R3_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
  r=2;
}


void
on_R4_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
  r=1;
}


void
on_B5_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
char cinm[20] ;
int status=1;
  GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9 ;

    input1 = lookup_widget(GTK_WIDGET(button), "id_modif");
    input2 = lookup_widget(GTK_WIDGET(button), "S4");
    input3 = lookup_widget(GTK_WIDGET(button), "S5");
    input4 = lookup_widget(GTK_WIDGET(button), "S6");
    input5 = lookup_widget(GTK_WIDGET(button),"combo3");
    input6 = lookup_widget(GTK_WIDGET(button),"combo4");
    input7 = lookup_widget(GTK_WIDGET(button),"R3");
    input8 = lookup_widget(GTK_WIDGET(button),"R4");
    input9 = lookup_widget(GTK_WIDGET (button),"modif1");
	strcpy(cinm,gtk_entry_get_text(GTK_ENTRY(input1)));
	if(strcmp(cinm,"") == 0){
		status = 0 ; 
	}
	int cinx= atoi(cinm);
	rendezvous rdv=chercher(cinx ,"rendezvous.txt");	
	strcpy(rdv.etablissement.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
	if(strcmp(rdv.etablissement.region,"") == 0){
		status = 0 ; 
	}
        strcpy(rdv.etablissement.nometablisssement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
	if(strcmp(rdv.etablissement.nometablisssement,"") == 0){
		status = 0 ; 
	}
	rdv.date.jours= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
	rdv.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
	rdv.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
	
 	 if(r==1) {
          strcpy(rdv.time,"matin") ; }
         if(r==2){
          strcpy(rdv.time,"apres midi") ;} 


		

	if(chercher(rdv.idrdv,"rendezvous.txt").idrdv != -1){
		if(status){     gtk_label_set_markup(GTK_LABEL(input9),"<b><span color='green'>*Donneur modifié avec succés ! </span></b>");
			
				int x=modifier(cinx,rdv,"rendezvous.txt");
				
				gtk_entry_set_text(GTK_ENTRY(input1), "");
        			
       				gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2), 1);
				gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), 5);
				gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4), 1999);
		         }
		else{
			gtk_label_set_markup(GTK_LABEL(input9),"<b><span color='red'>*Veuillez remplir tout les champs !</span></b>");               }
                                                           }
       else{
		gtk_label_set_markup(GTK_LABEL(input9),"<b><span color='red'>*ID NON EXISTANT ! </span></b>");
	}
}





void
on_supp_rann_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *is , *L1;
	char id[20];

	is = lookup_widget(GTK_WIDGET (button),"is");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(is)));
	int idx=atoi(id);



	L1= lookup_widget(GTK_WIDGET (button),"L1");

	if(chercher(idx,"rendezvous.txt").idrdv != -1){
		gtk_label_set_markup(GTK_LABEL(L1),"<b><span color='green'>*RDV supprimé avec succés ! </span></b>");
		
		supprimer(idx,"rendezvous.txt");
		gtk_entry_set_text(GTK_ENTRY(is), "");
	}
	else{
		gtk_label_set_markup(GTK_LABEL(L1),"<b><span color='red'>*RDV NON EXISTANT ! </span></b>");
		gtk_entry_set_text(GTK_ENTRY(is), "");
	
	}
}


void
on_historique_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar a1_nom[20];
gchar a1_prenom[30];
gchar a1_nometablisssement[30];
gchar a1_groupesanguine[30];
gchar a1_time[30];
gchar a1_region[20];
gint  a1_idrdv;
gint  a1_jours;
gint  a1_mois;
gint  a1_annee;

rendezvous rdv;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model, &iter, path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&a1_idrdv,1,&a1_nom,2,&a1_prenom,3,&a1_groupesanguine,4,&a1_region,5,&a1_jours,6,&a1_mois,7,&a1_annee,8,&a1_nometablisssement,9,&a1_time,-1);

a1_idrdv=rdv.idrdv;
int n=0;
n=supprimer(a1_idrdv,"rendezvouz.txt");
afficher_rdv(treeview);
//on_aff_his_clicked(objet,user_data);
}



}


void
on_aff_his_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *historique;
GtkWidget *gestion_rdv;
GtkWidget *m_aff;

    m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    m_aff=create_window_historique();
    gtk_widget_show(m_aff);
    gtk_init(&argc,&argv);
    chang_background(m_aff,1000,520,"B.jpg");
historique=lookup_widget(m_aff,"historique");
afficher_vider(historique);
afficher_rdv(historique);
}



void
on_button_res_rdv_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget       *objet;
GtkWidget *res_rdv_input;
GtkWidget *historique;
GtkWidget *window_historique;
GtkWidget *m_aff;

char ID[20];
int idrdv=0;
int cher=0;
    res_rdv_input= lookup_widget(GTK_WIDGET(button), "res_rdv_input");
    strcpy(ID, gtk_entry_get_text(GTK_ENTRY(res_rdv_input)));
    idrdv=atoi(ID);

    m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    m_aff=create_window_historique();
    gtk_widget_show(m_aff);
    gtk_init(&argc,&argv);

    chang_background(m_aff,1000,520,"B.jpg");
    cher=chercher_historique(idrdv ,"rendezvous.txt","rendezvous_aux.txt");

if(cher!=0)
{
historique=lookup_widget(m_aff,"historique");
afficher_historique_rdv(historique,"rendezvous_aux.txt");
}
else
{
//msh err
}

}



void
on_histo_win_disp_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_aff;

m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_aff=create_window_historique();
gtk_widget_show(m_aff);

chang_background(m_aff,1000,520,"B.jpg");
}




void
on_theme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(img1,"A.jpg");
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_gestion_rdv();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);

}


void
on_theme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(img1,"B.jpg");
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_gestion_rdv();
gtk_widget_show(m_modif);


gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
    
}


void
on_theme_btn_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}

int x=1;
void
on_radiostat2_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
  x=2;
}

void
on_radiostat1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
  x=1;
}


void
on_B10_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input1,*input6 ,*input7, *input8, *input9,*m1;
char cap[20];
int capint=0;
int result=0;
rendezvous rdv;

    input1 = lookup_widget(GTK_WIDGET(button), "entrycapacite");
    strcpy(cap,gtk_entry_get_text(GTK_ENTRY(input1))); 
    capint=atoi(cap);
    input6 = lookup_widget(GTK_WIDGET(button), "comboets");
    if(strcmp("ETS1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)))==0)
       strcpy(rdv.etablissement.nometablisssement,"ETS1");
else if (strcmp("ETS2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)))==0)
       {
       strcpy(rdv.etablissement.nometablisssement,"ETS2");}
else if (strcmp("ETS3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)))==0)
       {
       strcpy(rdv.etablissement.nometablisssement,"ETS3");
       }
    input7 = lookup_widget(GTK_WIDGET(button), "SSJ1");
    input8 = lookup_widget(GTK_WIDGET(button), "SSM2");
    input9= lookup_widget(GTK_WIDGET(button), "SSA3");

     rdv.date.jours= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
     rdv.date.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
     rdv.date.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));

if(x==1){
        strcpy(rdv.time,"matin") ; }
if(x==2){
        strcpy(rdv.time,"apresmidi") ;}
char jour[20];
char mois[20];
char annee[20];
char nb[10]="";

result=Horaire("rendezvous.txt",capint,jour,mois,annee,rdv.time);

sprintf(jour,"%d",rdv.date.jours);
sprintf(mois,"%d",rdv.date.mois);
sprintf(annee,"%d",rdv.date.annee);
sprintf(nb,"%d",result-1);

m1=lookup_widget(GTK_WIDGET(button),"result_ran");
gtk_label_set_text(GTK_LABEL(m1),nb);

}

void
on_statistique_btn_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_aff;

    m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    m_aff=create_window_statistique();
    gtk_widget_show(m_aff);
    gtk_init(&argc,&argv);
    chang_background(m_aff,1000,520,"B.jpg");
}

