import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;



public class MainListePotions {

	public static void main(String[] args) {
		String requete;
		
		try
    	{
    		Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/lesgaulois","root","");
			Statement st = conn.createStatement();
	    	
			requete = "SELECT * FROM potion ORDER BY NOM_POTION";					
			
			ResultSet rec = st.executeQuery(requete);

	    	while(rec.next())
	    	{
	    		System.out.println("Potion : "+rec.getString("NOM_POTION"));
	    		
	    		requete = "SELECT * " +
				" FROM compose, ingredient " +
				" WHERE " +
				" ID_POTION = " + rec.getInt("ID_POTION") +
				" AND compose.ID_INGREDIENT = ingredient.ID_INGREDIENT";
	    	
				Statement st2 = conn.createStatement();
				ResultSet rec2 = st2.executeQuery(requete);
				System.out.println("Composition : ");
		    	while(rec2.next())
		    	{
		    		System.out.println(".... "+rec2.getString("NOM_INGREDIENT"));
		    	}
				st2.close();		    	
	    	}
			st.close();
		}
		catch (Exception e)		    
		{
			System.out.println("ERREUR " + e.toString());
		}

	}

}
