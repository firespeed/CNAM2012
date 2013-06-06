/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dessin;

/**
 *
 * @author rewiko
 */
public class CLigne extends CFigure {
    private int x2;
    private int y2;
    
    public CLigne() {
    }

    public CLigne(int x1, int y1,int x2, int y2) {
        super(x1,y1);
        this.x2 = x2;
        this.y2 = y2;
    }

    public CLigne(int ipx1, int ipx2) {
        super(ipx1, ipx2);
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
