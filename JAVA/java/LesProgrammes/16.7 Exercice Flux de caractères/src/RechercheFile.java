import java.io.BufferedReader;
import java.io.FileReader;


public class RechercheFile {

	public static int analyseChaine(String contenu, String chaineCherchee) 
	{
		int nbTrouve=0;
		int longChaine = chaineCherchee.length();
		int longContenu = contenu.length();
		for(int i=0;i<longContenu-longChaine;i++)
		{
			String NChaine=contenu.substring(i,i+longChaine);			
			if(NChaine.compareTo(chaineCherchee)==0)
			{
				nbTrouve+=1;
			}
		}
		return nbTrouve;
	}
	
	public static void main(String[] args) {
		
		String nomFichier;
		String chaineRecherche;
		
		String contenuFinal;
		
		System.out.print("Nom complet du fichier : ");
		nomFichier = Clavier.lireString();
		System.out.println();
		
		System.out.print("Chaine de caract�res recherch�e : ");
		chaineRecherche = Clavier.lireString();
		
		boolean eof = false;
		int numLigne=0;
		int nbTrouve=0;
		
		String affichage = "";
		// Recherche de la chaine dans le fichier
		try {
	        FileReader file = new FileReader(nomFichier);
		    BufferedReader buff = new BufferedReader(file);

	        while (!eof) {
        		String line = buff.readLine();
            	if (line == null)
            	{
            		eof = true;
					affichage += affichage +nbTrouve+" occurence(s) trouv�e(s), aux ligne(s) :"+"\n";
				}
            	else
            	{
					numLigne++;
					int nb = analyseChaine(line,chaineRecherche);
					if(nb>0)
					{
						nbTrouve+=nb;
                		affichage += numLigne+" "+line+"\n";
					}
				}
			}
		} catch (Exception e)
		{
			System.out.println("Error -- " + e.toString());
		}
		System.out.println(affichage);
	}

}
