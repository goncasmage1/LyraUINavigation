# LyraUINavigation
Lyra's UI Navigation logic extracted into its own plugin

In order to add Lyra UI Navigation into a Blueprint-only project, you'll have to download the binaries from this repository and extract them into <Engine Installation Folder>/Engine/Plugins/Marketplace. After doing this and opening your project, you should be able to enable the plugin by going to Plugins -> User Interface.

After adding this plugin to your project and enabling it, be sure to:
- Go to Project Settings and update the following properties:
  - [Game / Common Input Settings] -> Game Instance Class = CommonGameInstance
  - [Project / Maps & Modes] -> Input Data = B_CommonInputData
  - [Engine / General Settings] -> Game Viewport Client Class = LyraGameViewportClient
  - [Engine / General Settings] -> Local Player Class = LyraLocalPlayer
  - [Engine / General Settings] -> Game User Settings Class = LyraSettingsLocal
  - [Plugins / Lyra UI Navigation] -> Default UI Policy Class = B_LyraUIPolicy
- Use the plugin's BP_LUIN_PlayerController or have your Player Controller class inherit from CommonPlayerController
