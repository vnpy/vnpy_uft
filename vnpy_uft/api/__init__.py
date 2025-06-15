from pathlib import Path

from .vnuftmd import MdApi             # noqa
from .vnufttd import TdApi             # noqa
from .uft_constant import *            # noqa

API_PATH = Path(__file__).parent
TEST_LICENSE = str(API_PATH.joinpath("license.dat"))
