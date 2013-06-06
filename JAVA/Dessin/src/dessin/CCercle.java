/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dessin;

/**
 *
 * @author rewik
 */
public class CCercle extends CFigure {
    private int rayon;

    public CCercle(int x1,int y1,int rayon){
        super(x1,y1);
      this.rayon=rayon;
    }
    
    public void CCercle(int xp){
      
    }
       
    public int getRayon() {
        return rayon;
    }

    public void setRayon(int rayon) {
        this.rayon = rayon;
    }

    @Override
    public void deplacer(int ipxd, int ipyd) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void trace() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
