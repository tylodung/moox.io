open BsReactNative;

let component = ReasonReact.statelessComponent("HeaderLarge");

let styles =
  StyleSheet.create(
    Style.{
      "menu":
        style([
          justifyContent(Center),
          alignItems(Center),
          borderTopWidth(10.),
          borderColor(String(Consts.Colors.dark)),
          shadowColor(String("#000")),
          shadowOffset(~width=0., ~height=5.),
          shadowOpacity(0.15),
          shadowRadius(20.),
          zIndex(1),
        ]),
      "bar":
        style([
          flexDirection(Row),
          flexWrap(Wrap),
          justifyContent(SpaceBetween),
        ]),
      "barWrapper": style([backgroundColor(String(Consts.Colors.light))]),
      "logo":
        style([
          flexDirection(Row),
          position(Relative),
          zIndex(1),
          paddingHorizontal(Pt(10.)),
          alignItems(Center),
        ]),
      "logoText":
        style([
          fontSize(Float(18.)),
          fontWeight(`_700),
          color(String(Consts.Colors.dark)),
        ]),
      "barLinks": style([flexDirection(Row)]),
      "barLink":
        style([
          padding(Pt(10.)),
          fontSize(Float(16.)),
          lineHeight(18. *. 1.7),
          color(String(Consts.Colors.dark)),
        ]),
      "barLinkActive":
        style([textDecorationLine(Underline), textDecorationStyle(Solid)]),
      "icons": style([flexDirection(Row)]),
      "icon":
        style([
          flexGrow(1.),
          flexShrink(0.),
          display(Flex),
          alignItems(Center),
          paddingHorizontal(Pt(12.)),
          paddingVertical(Pt(6.)),
          fontSize(Float(12.)),
        ]),
    },
  );

let make = (~currentLocation, _children) => {
  ...component,
  render: _self =>
    <View style=styles##menu>
      <Container style=styles##bar wrapperStyle=styles##barWrapper>
        <ViewLink style=styles##logo href="/">
          <SVGLogo width=20. height=20. fill=Consts.Colors.dark />
          <Text style=styles##logoText>
            {("  " ++ Consts.title)->ReasonReact.string}
          </Text>
        </ViewLink>
        <View style=styles##barLinks>
          {Consts.menuLinks
           /* ->Belt.Array.sliceToEnd(1) */
           ->Belt.Array.map(item => {
               let isActive =
                 item.isActive(currentLocation##pathname, item.link);
               <TextLink
                 key={item.link}
                 href={item.link}
                 style=Style.(
                   concat([
                     styles##barLink,
                     isActive ? styles##barLinkActive : style([]),
                   ])
                 )>
                 {item.text |> R.string}
               </TextLink>;
             })
           ->ReasonReact.array}
        </View>
        <SocialIcons
          wrapperStyle=styles##icons
          iconStyle=styles##icon
          iconSize=22.
          iconColor=Consts.Colors.dark
        />
      </Container>
    </View>,
};

[@bs.deriving abstract]
type jsProps = {currentLocation: {. "pathname": string}};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~currentLocation=jsProps->currentLocationGet, [||])
  );
