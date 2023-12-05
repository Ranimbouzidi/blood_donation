#ifndef RDVRANIM_H_INCLUDED
#define RDVRANIM_INCLUDED
#include <gtk/gtk.h>
typedef struct {
char nometablisssement[20];
int capacite;
char region[50]; 
}etablissement;
typedef struct {
char nom[20];
char prenom[20]; 
char groupesanguine[20];

}donneur;

GtkTreeIter iter;
GtkWidget *liste;

typedef struct {
int jours;
int mois;
int annee; 
}date;
typedef struct {
int idrdv;
etablissement etablissement;
donneur donneurs;
date date;
char time[100];


}rendezvous;


int ajouter(rendezvous rdv, char *filename) ;
int modifier(int id, rendezvous nouv, char *filename);
int supprimer(int id, char *filename);
rendezvous chercher(int id, char *filename);
void afficher_rdv(GtkWidget *liste);
void afficher_vider(GtkWidget *liste);
int chercher_historique(int idrdv ,char *f_main,char *f_aux);
void afficher_historique_rdv(GtkWidget *liste,char *f_aux);
void chercher_vider(GtkWidget *tree_view);
int Horaire(char *filename, int cap, char jour[], char mois[] , char annee[], char heure[]);

#endif
