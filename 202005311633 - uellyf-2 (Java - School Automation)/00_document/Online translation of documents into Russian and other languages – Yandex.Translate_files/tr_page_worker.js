!function(n,s,o){"use strict";o.worker={events:{load:n,unload:n,resize:n,scroll:n,message:n,DOMContentLoaded:s},userScroll:!0,translator:null,initialize:function(t){var e=this.events;t=t||{},Object.keys(e).forEach(function(t){e[t].addEventListener(t,this,!1)},this),t.href=n.location.href,this.sendMessage("inited",t)},loadHandler:function(){this.sendMessage("loaded")},handleEvent:function(t){this[t.type+"Handler"](t)},sendMessage:function(t,e){n.parent.postMessage(JSON.stringify({type:t,data:e}),"*")},unloadHandler:function(){var e=this.events;this.sendMessage("unloading"),this.translator&&(this.translator.halt(),this.translator=null),Object.keys(e).forEach(function(t){e[t].removeEventListener(t,this,!1)},this)},scrollHandler:function(){var t=this.getScrollInfo();this.userScroll?this.sendMessage("scrolling",{x:t.x/(t.W-t.w),y:t.y/(t.H-t.h)}):this.userScroll=!0},resizeHandler:function(){var t=s.body,e={};t&&(e.height=Math.max(t.scrollHeight,t.offsetHeight)),this.sendMessage("resized",e)},getScrollInfo:function(){var t="BackCompat"===s.compatMode?s.body:s.documentElement;return{x:n.pageXOffset||t.scrollLeft,y:n.pageYOffset||t.scrollTop,w:t.clientWidth,h:t.clientHeight,W:t.scrollWidth,H:t.scrollHeight}},messageHandler:function(t){var e,s,a=this,r=t.data;try{r=JSON.parse(r)}catch(t){r=null}if(r)switch(r.type){case"undo":this.translator&&this.translator.undo();break;case"redo":this.translator&&this.translator.redo();break;case"halt":this.translator&&this.translator.halt();break;case"start":o.trDir=[r.data.sourceLang,r.data.targetLang].join("-"),this.translator&&(this.translator.undo(),this.translator.translate(r.data.sourceLang,r.data.targetLang));break;case"create":if(this.translator)break;s=r.data||o.config,this.translator=new o.PageTranslator(s),this.translator.on("complete",function(){a.sendMessage("complete")}).on("progress",function(t){a.sendMessage("progress",t)}).on("error",function(t){a.sendMessage("partialError",t)}),s.useAlign&&o.createPopup(this.translator);break;case"rename":n.name=r.data;break;case"scroll":this.userScroll=!1,e=this.getScrollInfo(),n.scroll(r.data.x*(e.W-e.w),r.data.y*(e.H-e.h))}},DOMContentLoadedHandler:function(){var t=s.body,e={};t&&(e.height=Math.max(t.scrollHeight,t.offsetHeight)),this.sendMessage("ready",e)}}}(this,this.document,this.yt=this.yt||{});