
import java.io.*;

public class TestFile {
  protected String nomFichier;
  protected File fichier;
  
  public TestFile(String nomFichier) {
    this.nomFichier = nomFichier;
    fichier = new File(nomFichier);
    traitement();
  }

  private void traitement() {
	    if (!fichier.exists()) { 
	      System.out.println("le fichier "+nomFichier+"n'existe pas");
	      System.exit(1);
	    }      
	     
	    System.out.println(" Nom du fichier    : "+fichier.getName());
	    System.out.println(" Chemin du fichier : "+fichier.getPath());
	    System.out.println(" Chemin absolu     : "+fichier.getAbsolutePath());
	    System.out.println(" Droit de lecture  : "+fichier.canRead()); 
	    System.out.println(" Droit d'ecriture  : "+fichier.canWrite());
	    
	    
 
	    if (!fichier.isFile() ) {
	      System.out.println(" contenu du repertoire ");
	      String fichiers[] = fichier.list();
	      for(int i = 0; i < fichiers.length; i++) System.out.println(i+"  "+fichiers[i]);
	    }     
	  }			
  
  public static void main(String args[]) {
    new TestFile(args[0]);
  }

  
}