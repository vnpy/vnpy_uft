from pathlib import Path

from .vnuftmd import MdApi
from .vnufttd import TdApi
from .uft_constant import *

API_PATH = Path(__file__).parent
TEST_LICENSE = str(API_PATH.joinpath("license.dat"))