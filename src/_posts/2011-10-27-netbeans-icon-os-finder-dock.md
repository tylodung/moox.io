---
lang: en
title: Keep one Netbeans icon in your OS X Finder Dock
author: MoOx
layout: post
permalink: /blog/netbeans-icon-os-finder-dock/
dsq_thread_id:
  - 264802206
categories:
  - IDE
  - Web Development
tags:
  - ide
  - netbeans
  - os x
---
After installing Netbeans, you drag the Netbeans.app in your dock. And each time you start Netbeans, you have a second Netbeans icon which appears… That’s boring.

Here is the solution <!--more-->:

Go into the `/Applications/Netbeans` folder, and open the Netbeans package.

[<img src="{{site.baseurl}}/medias/2011/10/open-netbeans-package.png" alt="" title="Open Netbeans.app package" width="541" height="207" class="aligncenter size-full wp-image-102" />][1]

Then open `etc/netbeans.conf`

[<img src="{{site.baseurl}}/medias/2011/10/open-netbeans-conf.png" alt="" title="Edit netbeans.conf" width="342" height="303" class="aligncenter size-full wp-image-103" />][2]

You should see in the file :

<code class="block"># Default location of JDK, can be overridden by using --jdkhome &lt;dir&gt;:
#netbeans_jdkhome="/path/to/jdk"</code>

Just add `netbeans_jdkhome="/System/Library/Frameworks/JavaVM.framework/Versions/CurrentJDK/Home/"` after theses lines.

Restart Netbeans and voilà !

 [1]: {{site.baseurl}}/medias/2011/10/open-netbeans-package.png
 [2]: {{site.baseurl}}/medias/2011/10/open-netbeans-conf.png