using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using entities.Concrete;
namespace Bll.Abstract
{
    public interface IKitaplarBll
    {
        List<kitaplar> getAll();

        kitaplar getOneByDepositId(int id);
        kitaplar getOneById(int id);
        kitaplar getOneBarcodeId(string barkod);
        void Update(kitaplar kitaplar);
        void Add(kitaplar kitaplar);
        void Delete(kitaplar kitaplar);
    }
}
