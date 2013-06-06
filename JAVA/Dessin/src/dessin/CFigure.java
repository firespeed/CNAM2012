/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dessin;

import java.awt.Graphics;

/**
 *
 * @author rewiko
 */
public abstract class  CFigure {
 
    protected int x1;
    protected int y1;
    Graphics g;
    
    public CFigure(){
        x1=0;
        y1=0;
    }

    public CFigure(int ipx1,int ipx2){
        x1=ipx1;
        y1=ipx2;
    }
    
    public abstract void deplacer(int ipxd,int ipyd);
    
    public abstract void trace();
    
    public int getX1() {
        return x1;
    }

    public void setX1(int x1) {
        this.x1 = x1;
    }

    public int getY1() {
        return y1;
    }

    public void setY1(int y1) {
        this.y1 = y1;
    }

    public Graphics getG() {
        return g;
    }

    public void setG(Graphics g) {
        this.g = g;
    }
    
}
