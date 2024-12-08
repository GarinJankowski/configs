import XMonad
import XMonad.Util.EZConfig
import XMonad.Layout.ThreeColumns
import XMonad.Layout.Magnifier
import XMonad.Hooks.EwmhDesktops
import XMonad.Hooks.DynamicLog
import XMonad.Hooks.ManageDocks
import XMonad.Hooks.StatusBar
import XMonad.Hooks.StatusBar.PP
import XMonad.Util.Run
import XMonad.Util.SpawnOnce
import Graphics.X11.ExtraTypes.XF86
import XMonad.Actions.PhysicalScreens
import qualified XMonad.StackSet as W

main :: IO ()
main = do
  mySB <- statusBarPipe "xmobar" (pure xmobarPP)
  spawn "xautolock -time 15 -locker slock"
  xmonad $ withSB mySB $ ewmhFullscreen $ ewmh $ docks $ myConfig

myLayout = tiled ||| Mirror tiled ||| Full ||| threeCol
  where
    threeCol = magnifiercz' 1.3 $ ThreeColMid nmaster delta ratio
    tiled = Tall nmaster delta ratio
    nmaster = 1 -- Default number of windows in the master pane
    ratio = 1/2 -- Default proportion of screen occupied by master pane
    delta = 3/100 -- Percent of screen to increment by when resizing panes

myConfig = def
    { modMask = mod4Mask -- Rebind Mod to the Super key
    , borderWidth = 0 -- remove borders
    , manageHook = manageDocks <+> manageHook def
    , layoutHook = avoidStruts $ myLayout
    }
  `additionalKeysP`
    [ ("M-S-t", spawn "sensible-terminal")
    , ("M-S-b", spawn "com.brave.Browser")
    , ("M-<Delete>", spawn "slock")
    , ("M-C-s", unGrab *> spawn "scrot -s")
    , ("<XF86MonBrightnessUp>", spawn "brightnessctl s +2%")
    , ("<XF86MonBrightnessDown>", spawn "brightnessctl s 2%-")
    , ("M-C-<Tab>", onNextNeighbour def W.view)
    , ("M-C-S-<Tab>", onPrevNeighbour def W.view)
    ]
