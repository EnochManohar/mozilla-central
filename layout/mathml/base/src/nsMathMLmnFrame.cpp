/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is Mozilla MathML Project.
 * 
 * The Initial Developer of the The Original Code is The University Of 
 * Queensland.  Portions created by The University Of Queensland are
 * Copyright (C) 1999 The University Of Queensland.  All Rights Reserved.
 * 
 * Contributor(s): 
 *   Roger B. Sidje <rbs@maths.uq.edu.au>
 *   Shyjan Mahamud <mahamud@cs.cmu.edu>
 */

#include "nsCOMPtr.h"
#include "nsHTMLParts.h"
#include "nsIHTMLContent.h"
#include "nsFrame.h"
#include "nsLineLayout.h"
#include "nsHTMLIIDs.h"
#include "nsIPresContext.h"
#include "nsHTMLAtoms.h"
#include "nsUnitConversion.h"
#include "nsIStyleContext.h"
#include "nsStyleConsts.h"
#include "nsStyleChangeList.h"
#include "nsINameSpaceManager.h"
#include "nsIRenderingContext.h"
#include "nsIFontMetrics.h"
#include "nsStyleUtil.h"

#include "nsIDOMText.h"
#include "nsITextContent.h"

#include "nsMathMLmnFrame.h"
#include "nsMathMLTextFrame.h"

//
// <mn> -- number - implementation
//

nsresult
NS_NewMathMLmnFrame(nsIPresShell* aPresShell, nsIFrame** aNewFrame)
{
  NS_PRECONDITION(aNewFrame, "null OUT ptr");
  if (nsnull == aNewFrame) {
    return NS_ERROR_NULL_POINTER;
  }
  nsMathMLmnFrame* it = new (aPresShell) nsMathMLmnFrame;
  if (nsnull == it) {
    return NS_ERROR_OUT_OF_MEMORY;
  }
  *aNewFrame = it;  
  return NS_OK;
}

nsMathMLmnFrame::nsMathMLmnFrame()
{
}

nsMathMLmnFrame::~nsMathMLmnFrame()
{
}

NS_IMETHODIMP
nsMathMLmnFrame::Init(nsIPresContext*  aPresContext,
                      nsIContent*      aContent,
                      nsIFrame*        aParent,
                      nsIStyleContext* aContext,
                      nsIFrame*        aPrevInFlow)
{
  nsresult rv = NS_OK;
  rv = nsMathMLContainerFrame::Init(aPresContext, aContent, aParent, aContext, aPrevInFlow);
  return rv;
}

NS_IMETHODIMP
nsMathMLmnFrame::Reflow(nsIPresContext*          aPresContext,
                        nsHTMLReflowMetrics&     aDesiredSize,
                        const nsHTMLReflowState& aReflowState,
                        nsReflowStatus&          aStatus)
{
  return ReflowTokenFor(this, aPresContext, aDesiredSize,
                        aReflowState, aStatus);
}

NS_IMETHODIMP
nsMathMLmnFrame::Place(nsIPresContext*      aPresContext,
                       nsIRenderingContext& aRenderingContext,
                       PRBool               aPlaceOrigin,
                       nsHTMLReflowMetrics& aDesiredSize)
{
  return PlaceTokenFor(this, aPresContext, aRenderingContext,
                       aPlaceOrigin, aDesiredSize);
}
