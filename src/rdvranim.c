#include "rdvranim.h"
#include<stdio.h>


int ajouter(rendezvous rdv, char *filename) {
    
   

    FILE *f = fopen(filename, "a");
    if (f != NULL) {
fprintf(f, "%d %s %s %s %s %d %d %d %s %s\n",rdv.idrdv  ,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,rdv.date.jours,rdv.date.mois,rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time);
        fclose(f);
        return 1; 
    } else {
        return 0; 
    }
}





rendezvous chercher(int id, char *filename) {
    rendezvous rdv;
    int tr = 0;
    FILE *f = fopen(filename, "r");

    if (f != NULL) {
        while (fscanf(f, "%d %s %s %s %s %d %d %d %s %s\n",          &rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,&rdv.date.jours,&rdv.date.mois,&rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time) != EOF) {
            if (id == rdv.idrdv) {
                tr = 1;
                break;
            }
        }
        fclose(f);
    } else {
       rdv.idrdv = -1;
    }

    if (tr == 0) {
        rdv.idrdv = -1;
    }

    return rdv;
}









int modifier(int id, rendezvous nouv, char *filename) {
   rendezvous resultat = chercher(id, filename);

    if (resultat.idrdv == -1) {
        return 2; 
    }

    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("aux.txt", "w");

    if (f == NULL || f2 == NULL) {
        if (f != NULL) fclose(f);
        if (f2 != NULL) fclose(f2);
        return 0; 
    }

    rendezvous rdv;
    while (fscanf(f, "%d %s %s %s %s %d %d %d %s %s\n",  &rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,&rdv.date.jours,&rdv.date.mois,&rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time) != EOF) {
        if (rdv.idrdv != id) {
            fprintf(f2, "%d %s %s %s %s %d %d %d %s %s\n",  nouv.idrdv,nouv.donneurs.nom,nouv.donneurs.prenom,nouv.donneurs.groupesanguine,nouv.etablissement.region,nouv.date.jours,nouv.date.mois,nouv.date.annee,
nouv.etablissement.nometablisssement,nouv.time);
        } else {
            fprintf(f2, "%d %s %s %s %s %d %d %d %s %s\n",  nouv.idrdv,nouv.donneurs.nom,nouv.donneurs.prenom,nouv.donneurs.groupesanguine,nouv.etablissement.region,nouv.date.jours,nouv.date.mois,nouv.date.annee,
nouv.etablissement.nometablisssement,nouv.time);
        }
    }

    fclose(f);
    fclose(f2);

    remove(filename);
    rename("aux.txt", filename);
    return 1; 
}



int supprimer(int id, char *filename) {
    rendezvous resultat = chercher(id, filename);

    if (resultat.idrdv == -1) {
        return 2; 
    }

    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("aux.txt", "w");

    if (f == NULL || f2 == NULL) {
        if (f != NULL) fclose(f);
        if (f2 != NULL) fclose(f2);
        return 0; 
    }

    rendezvous rdv;
    while (fscanf(f, "%d %s %s %s %s %d %d %d %s %s\n",  &rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,&rdv.date.jours,&rdv.date.mois,&rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time) != EOF) {
        if (rdv.idrdv != id) {
            fprintf(f2, "%d %s %s %s %s %d %d %d %s %s\n",  rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,rdv.date.jours,rdv.date.mois,rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time);
        }
    }

    fclose(f);
    fclose(f2);

    remove(filename);
    rename("aux.txt", filename);
    return 1; 
}






enum
{
	CIN,
	NOM,
	PRENOM,
	GRP,
	REGION,
	JOUR,
	MOIS,
	ANNEE,
	ETS,
	TIME,
	COLUMNS,
};


void afficher_rdv(GtkWidget *liste)
{

FILE *f;

	rendezvous rdv;
	f=fopen("rendezvous.txt","a+");
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


store=NULL;
store = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));

if (f==NULL)
return;
else
{

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Groupe",renderer,"text",GRP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Region",renderer,"text",REGION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",ETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Periode",renderer,"text",TIME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


store=gtk_list_store_new(COLUMNS ,G_TYPE_INT ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT ,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);

while(fscanf(f, "%d %s %s %s %s %d %d %d %s  %s\n",&rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,&rdv.date.jours,&rdv.date.mois,&rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time)!=EOF)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CIN,rdv.idrdv,NOM,rdv.donneurs.nom,PRENOM,rdv.donneurs.prenom,GRP,rdv.donneurs.groupesanguine,REGION,rdv.etablissement.region,JOUR,rdv.date.jours,MOIS,rdv.date.mois,ANNEE,rdv.date.annee,
ETS,rdv.etablissement.nometablisssement,TIME,rdv.time,-1);

}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}


void afficher_vider(GtkWidget *tree_view)
{
    GtkWidget *parent_container = gtk_widget_get_parent(tree_view);
    gtk_container_remove(GTK_CONTAINER(parent_container), tree_view);
    gtk_widget_destroy(tree_view);
    GtkWidget *historique = gtk_tree_view_new();
    gtk_widget_set_name(historique, "historique");

    GtkListStore *store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(historique), GTK_TREE_MODEL(store));


    gtk_container_add(GTK_CONTAINER(parent_container), historique);

    gtk_widget_show_all(parent_container);

    afficher_rdv(historique);
}


//------------------------------------------------------------------------------------------------------------
void afficher_historique_rdv(GtkWidget *liste,char *f_aux)
{
FILE *f;

	rendezvous rdv;
	f=fopen(f_aux,"a+");
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


store=NULL;
store = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));

if (f==NULL)
return;
else
{

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Groupe",renderer,"text",GRP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Region",renderer,"text",REGION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",ETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Periode",renderer,"text",TIME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


store=gtk_list_store_new(COLUMNS ,G_TYPE_INT ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT ,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);

while(fscanf(f, "%d %s %s %s %s %d %d %d %s  %s\n",&rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,&rdv.date.jours,&rdv.date.mois,&rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time)!=EOF)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CIN,rdv.idrdv,NOM,rdv.donneurs.nom,PRENOM,rdv.donneurs.prenom,GRP,rdv.donneurs.groupesanguine,REGION,rdv.etablissement.region,JOUR,rdv.date.jours,MOIS,rdv.date.mois,ANNEE,rdv.date.annee,
ETS,rdv.etablissement.nometablisssement,TIME,rdv.time,-1);

}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}

int chercher_historique(int idrdv ,char *f_main,char *f_aux)
{
   rendezvous resultat = chercher(idrdv, f_main);
   remove(f_aux);

    if (resultat.idrdv == -1) {
        return 0; 
    }

    FILE *f = fopen(f_main, "r");
    FILE *f2 = fopen(f_aux, "a");

    if (f == NULL || f2 == NULL) {
        if (f != NULL) fclose(f);
        if (f2 != NULL) fclose(f2);
        return 0; 
    }

    rendezvous rdv;
    while (fscanf(f, "%d %s %s %s %s %d %d %d %s %s\n",  &rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,&rdv.date.jours,&rdv.date.mois,&rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time) != EOF) {
        if (rdv.idrdv == idrdv) {
            fprintf(f2, "%d %s %s %s %s %d %d %d %s %s\n",  rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,rdv.date.jours,rdv.date.mois,rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time);
        } 
    }

    fclose(f);
    fclose(f2);
 return 1;
}


void chercher_vider(GtkWidget *tree_view)
{
    GtkWidget *parent_container = gtk_widget_get_parent(tree_view);

     gtk_container_remove(GTK_CONTAINER(parent_container), tree_view);
    gtk_widget_destroy(tree_view);

    GtkWidget *new_tree_view = gtk_tree_view_new();
    gtk_widget_set_name(new_tree_view, "historique");

    GtkListStore *store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(new_tree_view), GTK_TREE_MODEL(store));


    gtk_container_add(GTK_CONTAINER(parent_container), new_tree_view);

    gtk_widget_show_all(parent_container);

    afficher_historique_rdv(new_tree_view,"rendezvous_aux.txt");
}
int Horaire(char *filename,int cap, char jour[], char mois[] , char annee[], char heure[])
{
    int nbr=0;
    int nbrd=0;
    rendezvous rdv;
    FILE *f=fopen(filename, "a");
    if(f!=NULL)
    {

        while(fscanf(f, "%d %s %s %s %s %d %d %d %s %s\n",  &rdv.idrdv,rdv.donneurs.nom,rdv.donneurs.prenom,rdv.donneurs.groupesanguine,rdv.etablissement.region,&rdv.date.jours,&rdv.date.mois,&rdv.date.annee,
rdv.etablissement.nometablisssement,rdv.time)!=EOF)
        {
            if( (strcmp(rdv.date.jours,jour)==0) && (strcmp(rdv.date.mois,mois)==0) && (strcmp(rdv.date.annee,annee)==0) && (strcmp(rdv.time,heure)==0))
            {
            nbr++;
            }
        }
    }
    fclose(f);
    if (nbr<cap)
    {
        return cap-nbr  ;
    }
    else
    return 0;
}

