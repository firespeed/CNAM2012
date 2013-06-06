<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
	xmlns:fo="http://www.w3.org/1999/XSL/Format">

<xsl:template match="/">
	 <fo:root>
		<fo:layout-master-set>
			<fo:simple-page-master 
				margin-right="1cm" 
				margin-left="1cm"
				margin-bottom="1cm" 
				margin-top="1cm"
				page-width="8.5cm" 
				page-height="11cm"
				master-name="first">
				<fo:region-body/>
			</fo:simple-page-master>
		</fo:layout-master-set>

		<fo:page-sequence master-reference="first">
			<fo:flow flow-name="xsl-region-body">
				  <xsl:apply-templates/>
			</fo:flow>
		</fo:page-sequence>
	  </fo:root>
</xsl:template>

<xsl:template match="plat|ingredient|realisation|histoire">
  <fo:block><xsl:apply-templates/></fo:block>
</xsl:template>
</xsl:stylesheet>